# Reversal Sorting  

You have an array that contains a permutation of integers 1,2,&hellip;,n. Your task is to sort the array in increasing order by reversing subarrays. You can construct any solution that has at most n reversals.

## Input

The first input line has an integer n: the size of the array. The array elements are numbered 1,2,&hellip;,n.
The next line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the contents of the array.

## Output

First print an integer k: the number of reversals.
After that, print k lines that describe the reversals. Each line has two integers a and b: you reverse a subarray from position a to position b.

## Constraints

* 1 &le; n &le; 2&middot;10<sup>5</sup>  

## Example

**Input:**
```c++
4
2 3 1 4
```

**Output:**
```c++
2
1 3
2 3
```
