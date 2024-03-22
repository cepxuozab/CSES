# Array Division
**Time limit:** 1.00 s **Memory limit:** 512 MB

You are given an array containing n positive integers.
Your task is to divide the array into k sub-arrays so that the maximum sum in a subarray is as small as possible

## Input
The first input line contains two integers n and k: the size of the array and the number of sub-arrays in the division.
The second line has n integers a<sub>1</sub>,a<sub>2</sub>,...,a<sub>n</sub>: the array values.

## Output
Print one integer: the maximum sum in a subarray in the optimal division.

## Constraints

- 1 &le; n &le; 2* 10<sup>5</sup>
- - 1 &le; k &le; n
- 1 &le; a<sub>i</sub> &le; 10<sup>9</sup>


## Example
### Input:
```
5 3
2 4 7 3 5
```
### Output:
```
8
```  

## <span style = "color:red"> Explanation:<span>
An optimal division is [2,4],[7],[3,5] where the sums of the sub-arrays are 6,7,8. The largest sum is the last sum 8.


