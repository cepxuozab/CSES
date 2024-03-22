# Prefix Sum Queries  

Given an array of n integers, your task is to process q queries of the following types:

- update the value at position k to u
- what is the maximum prefix sum in range [a,b]?  

## Input 
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".

## Output
Print the result of each query of type 2.

## Constraints

- 1 &le; n, q &le; 2 &times; 10<sup>5</sup>
- -10<sup>9</sup> &le; x<sub>i</sub>, u &le; 10<sup>9</sup>
- 1 &le; k &le; n 
- 1 &le; a &le; b &le; n

## Example1
<font color="blue">**Input:**</font> 
```c++
8 4
1 2 -1 3 1 -5 1 4
2 2 6
1 4 -2
2 2 6
2 3 4
```
<font color="blue">**Output:**</font>
```c++
5
2
0
```  





