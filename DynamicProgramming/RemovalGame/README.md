# Removal Game

There is a list of n numbers and two players who move alternately. On each move, a player removes either the first or last number from the list, and their score increases by that number. Both players try to maximize their scores.
What is the maximum possible score for the first player when both players play optimally?

## Input

The first input line contains an integer n: the size of the list.
The next line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the contents of the list.

## Output
Print the maximum possible score for the first player.


## Constraints

- 1 &le; n &le;  5000 
- -10<sup>9</sup> &le; x<sub>i</sub> &le;  10<sup>9</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
4
4 5 1 3
```
<font color="blue">**Output:**</font>
```c++
8
``` 
