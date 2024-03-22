# Another Game

There are n heaps of coins and two players who move alternately. On each move, a player selects some of the nonempty heaps and removes one coin from each heap. The player who removes the last coin wins the game.
Your task is to find out who wins if both players play optimally.

## Input

The first input line contains an integer t: the number of tests. After this, t test cases are described:
The first line contains an integer n: the number of heaps.
The next line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the number of coins in each heap.

## Output

For each test case, print "first" if the first player wins the game and "second" if the second player wins the game.


## Constraints

* 1 &le; t &le; 2&times;10<sup>5</sup>
* 1 &le; n &le; 2&times;10<sup>5</sup>
* 1 &le; x<sub>i</sub> &le; i10<sup>9</sup>
* the sum of all n is at most 2&times;10<sup>5</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
3
3
1 2 3
2
2 2
4
5 5 4 5
```
<font color="blue">**Output:**</font>
```c++
first
second
first
``` 
