# Xor Pyramid

Consider a xor pyramid where each number is the xor of lower-left and lower-right numbers. Here is an example pyramid:  
<p align="center">
  <img width="460" height="300" src=pyramidi.png>
</p>  

Given the bottom row of the pyramid, your task is to find the topmost number.  

## Input
The first input line has an integer n: the size of the pyramid.
The next line has n integers a<sub>1</sub>,a<sub>2</sub>,&hellip;,a<sub>n</sub>: the bottom row of the pyramid.  

## Output

Print one integer: the topmost number.

## Constraints

* 1 &le; n &le; 2&middot;10<sup>5</sup>
* 1 &le; a<sub>i</sub> &le; 10<sup>9</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
001011
8
2 10 5 12 9 5 1 5
```
<font color="blue">**Output:**</font>
```c++
9
``` 
