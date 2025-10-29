# Coin Arrangement

There is a 2 &times; n grid who's each cell contains some number of coins. The total number of coins is 2n.
Your task is to arrange the coins so that each cell contains exactly one coin. On each move you can choose any coin and move it one step left, right, up or down.
What is the minimum number of moves if you act optimally?

## Input

The first input line has an integer n: the width of the grid.
After this, there are two lines that describe the grid. Each line has n integers: the number of coins in each cell.

## Output

Print one integer: the minimum number of moves.

## Constraints   

* 1 &le; n &le; 10<sup>5</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
4
0 1 0 1
2 0 1 3
```
<font color="blue">**Output:**</font>
```c++
5
```   

