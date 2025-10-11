# Sliding Window Cost
**Time limit:** 1.00 s **Memory limit:** 512 MB

You are given an array of n integers. Your task is to calculate for each window of k elements, from left to right, the minimum total cost of making all elements equal.
You can increase or decrease each element with cost x where x is the difference between the new and the original value. The total cost is the sum of such costs.

## Input

The first input line contains two integers n and k: the number of elements and the size of the window.
The next line has n integers x<sub>1</sub>,x<sub>2</sub>,...,x<sub>n</sub>: the contents of the array.

## Output
Output n-k+1 values: the costs.

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
2 2 5 7 7 1
```  
