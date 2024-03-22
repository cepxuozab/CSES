# Stair Game

There is a staircase consisting of n stairs, numbered 1,2,&hellip;,n. Initially, each stair has some number of balls.
There are two players who move alternately. On each move, a player chooses a stair k where k &ne; 1 and it has at least one ball. Then, the player moves any number of balls from stair k to stair k-1. The player who moves last wins the game.
Your task is to find out who wins the game when both players play optimally.
Note that if there are no possible moves at all, the second player wins.

## Input

The first input line has an integer t: the number of tests. After this, t test cases are described:
The first line contains an integer n: the number of stairs.
The next line has n integers p<sub>1</sub>,p<sub>2</sub>,&hellip;,p<sub>n</sub>: the initial number of balls on each stair.

## Output

For each test, print "first" if the first player wins the game and "second" if the second player wins the game.


## Constraints

* 1 &le; t &le; 2&times;10<sup>5</sup>
* 1 &le; n &le; 2&times;10<sup>5</sup>
* 1 &le; p<sub>i</sub> &le; 10<sup>9</sup>
* the sum of all n is at most 2&times;10<sup>5</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
3
3
0 2 1
4
1 1 1 1
2
5 3
```
<font color="blue">**Output:**</font>
```c++
first
second
first
``` 
