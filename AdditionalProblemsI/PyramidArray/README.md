# Pyramid Array

You are given an array consisting of n distinct integers. On each move, you can swap any two adjacent values.
You want to transform the array into a pyramid array. This means that the final array has to be first increasing and then decreasing. It is also allowed that the final array is only increasing or decreasing.
What is the minimum number of moves needed?

## Input

The first input line has an integer n: the size of the array.
The next line has n distinct integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>2</sub>: the contents of the array.

## Output

Print one integer: the minimum number of moves.  

## Constraints

* 1 &le; n &le; 2&middot;10<sup>5</sup>
* 1 &le; x<sub>i</sub> &le; 10<sup>9</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
4
2 1 5 3
```
<font color="blue">**Output:**</font>
```c++
1
``` 

## Explanation:
You may swap the first two values which creates a pyramid array [1,2,5,3].