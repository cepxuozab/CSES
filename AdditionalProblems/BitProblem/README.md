# Bit Problem 

Given a list of n integers, your task is to calculate for each element x:

1. the number of elements y such that x &mid; y &equals; x
2. the number of elements y such that x & y &equals; x
3. the number of elements y such that x & y &ne; 0

## Input

The first input line has an integer n: the size of the list.
The next line has n integers x<sub>i</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the elements of the list.

## Output

Print n lines: for each element the required values.

## Constraints

* 1 &le; n &le; 2&middot;10<sup>5</sup>
* 1 &le; x<sub>i</sub> &le; 10<sup>6</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
5
3 7 2 9 2
```
<font color="blue">**Output:**</font>
```c++
3 2 5
4 1 5
2 4 4
1 1 3
2 4 4
```   
