在 WSL 安装过程:
1, 安装boost
sudo apt-get install libboost-all-dev
如果有报错,先更新aliyun: sudo apt-get update

2, 安装Z3
1, git clone https://github.com/Z3Prover/z3.git
2, 编译安装
python scripts/mk_make.py
cd build
make
sudo make install

编译solidity:
mkdir build && cd build
cmake .. && make