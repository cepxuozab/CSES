# Distinct Values Queries  

You are given an array of n integers and q queries of the form: how many distinct values are there in a range [a,b]?

## Input 
The first input line has two integers n and q: the array size and number of queries.
The next line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the array values.
Finally, there are q lines describing the queries. Each line has two integers a and b.

## Output
For each query, print the number of distinct values in the range.

## Constraints

- 1 &le; n, q &le; 2 &times; 10<sup>5</sup>
- 1 x<sub>i</sub> &le; 10<sup>9</sup>
- 1 &le; a &le; b &le; n

## Example1
<font color="blue">**Input:**</font> 
```c++
5 3
3 2 3 1 2
1 3
2 4
1 5
```
<font color="blue">**Output:**</font>
```c++
2
3
3
```  





