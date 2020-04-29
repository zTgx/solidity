# Deep Into Solidity 
Learning Solidity's implementation.

## Table of Contents
- [Build and Install](#build-and-install)
- [Example](#example)

## Build and Install
[build && install](https://github.com/zTgx/solidity/blob/master/INSTALL_README.md)

## Example

A "Hello World" program in Solidity is of even less use than in other languages, but still:

```solidity
pragma solidity ^0.6.0;

contract HelloWorld {
  function helloWorld() external pure returns (string memory) {
    return "Hello, World!";
  }
}
```
