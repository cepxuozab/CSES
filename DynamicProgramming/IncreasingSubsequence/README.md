# Increasing Subsequence

You are given an array containing n integers. Your task is to determine the longest increasing subsequence in the array, i.e., the longest subsequence where every element is larger than the previous one.
A subsequence is a sequence that can be derived from the array by deleting some elements without changing the order of the remaining elements.

## Input

The first line contains an integer n: the size of the array.
After this there are n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>x<sub>i</sub>: the contents of the array.

## Output

Print the length of the longest increasing subsequence.

## Constraints

- 1 &le; n &le; 2 \&times; 10<sup>5</sup>
1 &le; x<sub>i</sub> &le; 10<sup>9</sup> 

## Example1
<font color="blue">**Input:**</font>
```c++
8
7 3 5 3 6 2 9 8
```
<font color="blue">**Output:**</font>
```c++
4
``` 
