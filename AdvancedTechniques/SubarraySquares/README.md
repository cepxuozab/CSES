# Subarray Squares

Given an array of n elements, your task is to divide into k subarrays. The cost of each subarray is the square of the sum of the values in the subarray. What is the minimum total cost if you act optimally?

## Input

The first input line has two integers n and k: the array elements and the number of subarrays. The array elements are numbered 1,2,&hellip;,n.
The second line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the contents of the array.

## Output

Print one integer: the minimum total cost.

## Constraints

* 1 &le; k &le; n  &le; 3000
* 1 &le; x<sub>i</sub>  &le; 10<sup>5</sup>


## Example

**Input:**
```c++
8 3
2 3 1 2 2 3 4 1
```

**Output:**
```c++
110
```  

## Explanation: 

An optimal solution is [2,3,1], [2,2,3], [4,1], whose cost is (2+3+1)^2+(2+2+3)^2+(4+1)^2=110.