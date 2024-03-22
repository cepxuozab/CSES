# Grundy's Game

There is a heap of n coins and two players who move alternately. On each move, a player chooses a heap and divides into two nonempty heaps that have a different number of coins. The player who makes the last move wins the game.
Your task is to find out who wins if both players play optimally.

## Input

The first input line contains an integer t: the number of tests.
After this, there are t lines that describe the tests. Each line has an integer n: the number of coins in the initial heap.

## Output

For each test case, print "first" if the first player wins the game and "second" if the second player wins the game.


## Constraints

* 1 &le; t &le; 10<sup>5</sup>
* 1 &le; n &le; 10<sup>5</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
3
6
7
8
```
<font color="blue">**Output:**</font>
```c++
first
second
first
``` 
