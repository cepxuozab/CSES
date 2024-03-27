# Permutation Inversions  

Your task is to count the number of permutations of 1,2,&hellip;,n that have exactly k inversions (i.e., pairs of elements in the wrong order).
For example, when n=4 and k=3, there are 6 such permutations:

* [1,4,3,2]
* [2,3,4,1]
* [2,4,1,3]
* [3,1,4,2]
* [3,2,1,4]
* [4,1,2,3]

## Input

The only input line has two integers n and k.

## Output

Print the answer modulo 10<sup>9</sup>+7

## Constraints

* 1 &le; n &le; 500
* 1 &le; k &le; n * (n-1)/2

## Example1
<font color="blue">**Input:**</font>
```c++
4 3
```
<font color="blue">**Output:**</font>
```c++
6
``` 