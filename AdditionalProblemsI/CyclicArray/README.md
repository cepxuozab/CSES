# Cyclic Array  

You are given a cyclic array consisting of n values. Each element has two neighbors; the elements at positions n and 1 are also considered neighbors.
Your task is to divide the array into sub-arrays so that the sum of each subarray is at most k. What is the minimum number of sub-arrays?

## Input

The first input line contains integers n and k.
The next line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the contents of the array.
There is always at least one division (i.e., no value in the array is larger than k).

## Output

Print one integer: the minimum number of sub-arrays.

## Constraints

* 1 &le; n &le; 2&middot;10<sup>5</sup>
* 1 &le; x<sub>i</sub> &le; 10<sup>9</sup>
* 1 &le; k &le; 10<sup>18</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
8 5
2 2 2 1 3 1 2 1
```
<font color="blue">**Output:**</font>
```c++
3
```    

## Explanation:  

We can create three sub-arrays: [2, 2, 1], [3, 1] and [2, 1, 2] (remember that the array is cyclic).