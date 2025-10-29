# Removing Digits II

You are given an integer n. On each step, you may subtract from it any one-digit number that appears in it.
How many steps are required to make the number equal to 0?

## Input

The only input line has an integer n.

## Output

Print one integer: the minimum number of steps.

## Constraints
* 1 &le; n &le; 10<sup>18</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
27
```
<font color="blue">**Output:**</font>
```c++
5
```   

## Explanation: 

An optimal solution is 27 &rightarrow; 20 &rightarrow; 18 &rightarrow; 10 &rightarrow; 9 &rightarrow; 0.
