# Sliding Window Median
**Time limit:** 1.00 s **Memory limit:** 512 MB

You are given an array of n integers. Your task is to calculate the median of each window of k elements, from left to right.
The median is the middle element when the elements are sorted. If the number of elements is even, there are two possible medians, and we assume that the median is the smallest of them.

## Input

The first input line contains two integers n and k: the number of elements and the size of the window.
The next line has n integers x<sub>1</sub>,x<sub>2</sub>,...,x<sub>n</sub>: the contents of the array.

## Output
Print n-k+1 values: the medians.

## Constraints

- 1 &le; k &le; n &le;  2* 10<sup>5</sup>
- 1 &le; x<sub>i</sub> &le;  10<sup>9</sup>



## Example
### Input:
```
8 3
2 4 3 5 8 1 2 1
```
### Output:
```
3 4 5 5 2 1
```  
