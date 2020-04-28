### Install(Ubuntu):
* install boost  
`sudo apt-get install libboost-all-dev`  
if not found `libboost-all-dev`,   
update aliyun source `aliyun: sudo apt-get update`

* install Z3  
git clone https://github.com/Z3Prover/z3.git  
`python scripts/mk_make.py`  
`cd build`
` make && sudo make install`

* build solidity  
`mkdir build && cd build`  
`cmake .. && make`

### Usage
./solc --bin helloworld.sol