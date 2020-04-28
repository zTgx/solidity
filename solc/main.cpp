/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * @author Christian <c@ethdev.com>
 * @date 2014
 * Solidity commandline compiler.
 */

#include <solc/CommandLineInterface.h>
#include <boost/exception/all.hpp>
#include <clocale>
#include <iostream>

using namespace std;

/*
The equivalent of setlocale(LC_ALL, "C") is called before any user code is run.
If the user has an invalid environment setting then it is possible for the call
to set locale to fail, so there are only two possible actions, the first is to
throw a runtime exception and cause the program to quit (default behaviour),
or the second is to modify the environment to something sensible (least
surprising behaviour).

The follow code produces the least surprising behaviour. It will use the user
specified default locale if it is valid, and if not then it will modify the
environment the process is running in to use a sensible default. This also means
that users do not need to install language packs for their OS.
*/
static void setDefaultOrCLocale()
{
#if __unix__
	if (!std::setlocale(LC_ALL, ""))
	{
		setenv("LC_ALL", "C", 1);
	}
#endif
}

/**
 * solc 编译器的入口函数 main 
 **/
int main(int argc, char** argv)
{
	std::cout << "::main" << std::endl;
	std::cout << "argc = " << argc << std::endl;
	std::cout << "argv: " << std::endl;
	for(int idx=0;idx<argc;idx++) {
		std::cout << "	argv[" << idx << "] = " << argv[idx] << std::endl;
	}

	setDefaultOrCLocale();

	// 从命令行读取参数及.sol代码文件
	solidity::frontend::CommandLineInterface cli;

	// 该方法主要是使用boost::program_options解析参数
	if (!cli.parseArguments(argc, argv))
		return 1;

	// compile
	if (!cli.processInput())
		return 1;

	bool success = false;
	try
	{
		success = cli.actOnInput();
	}
	catch (boost::exception const& _exception)
	{
		cerr << "Exception during output generation: " << boost::diagnostic_information(_exception) << endl;
		success = false;
	}

	std::cout << "return main with result: " << success << std::endl;

	return success ? 0 : 1;
}
