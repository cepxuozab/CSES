# Increasing Subsequence II

Given an array of n integers, your task is to calculate the number of increasing subsequences it contains. If two subsequences have the same values but in different positions in the array, they are counted separately.

## Input

The first input line has an integer n: the size of the array.
The next line has n distinct integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>2</sub>: the contents of the array.

## Output

Print one integer: the number of increasing subsequences modulo 10<sup>9</sup> + 7.

## Constraints

* 1 &le; n &le; 2&middot;10<sup>5</sup>
* 1 &le; x<sub>i</sub> &le; 10<sup>9</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
3
2 1 3
```
<font color="blue">**Output:**</font>
```c++
5
``` 

## Explanation:
The increasing subsequences are [2], [1], [3], [2,3] and [1,3].