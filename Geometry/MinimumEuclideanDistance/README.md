# Minimum Euclidean Distance  

Given a set of points in the two-dimensional plane, your task is to find the minimum Euclidean distance between two distinct points.
The Euclidean distance of points (x<sub>1</sub>,y<sub>1</sub>) and (x<sub>2</sub>,yx<sub>2</sub>) is &radic;{(x<sub>1</sub>-x<sub>2</sub>)&sup2; + (y<sub>1</sub>-y<sub>2</sub>)&sup2;}.  

## Input  
The first input line has an integer n: the number of points.
After this, there are n lines that describe the points. Each line has two integers x and y. You may assume that each point is distinct.


## Output
Print one integer: d&sup2; where d is the minimum Euclidean distance (this ensures that the result is an integer).

## Constraints

- 2  &le; n  &le; 10<sup>5</sup> 
- -10<sup>9</sup> &le; x, y &le; 10<sup>9</sup>


## Example1
<font color="blue">**Input:**</font> 
```c++
4
2 1
4 4
1 2
6 3
```
<font color="blue">**Output:**</font>
```c++
2
```  



