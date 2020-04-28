# Deep Into Solidity 


Solidity is a statically typed, contract-oriented, high-level language for implementing smart contracts on the Ethereum platform.

## Table of Contents

- [Background](#background)
- [Build and Install](#build-and-install)
- [Example](#example)
- [Maintainers](#maintainers)

## Background

Solidity is a statically-typed curly-braces programming language designed for developing smart contracts
that run on the Ethereum Virtual Machine. Smart contracts are programs that are executed inside a peer-to-peer
network where nobody has special authority over the execution, and thus they allow to implement tokens of value,
ownership, voting and other kinds of logics.

When deploying contracts, you should use the latest released version of Solidity. 

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

## Maintainers
* [@zTgx](https://github.com/zTgx)

