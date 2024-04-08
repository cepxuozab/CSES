# Knuth Division

Given an array of n numbers, your task is to divide it into n subarrays, each of which has a single element.
On each move, you may choose any subarray and split it into two subarrays. The cost of such a move is the sum of values in the chosen subarray.
What is the minimum total cost if you act optimally?

## Input

The first input line has an integer n: the array size. The array elements are numbered 1,2,&hellip;,n.
The second line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the contents of the array.

## Output

Print one integer: the minimum total cost.


## Constraints

* 1 &le;  n  &le; 5000
* 1 &le; x<sub>i</sub>  &le; 10<sup>9</sup>


## Example

**Input:**
```c++
5
2 7 3 2 5
```

**Output:**
```c++
43
```  
