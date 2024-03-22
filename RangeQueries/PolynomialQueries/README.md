# Polynomial Queries

Your task is to maintain an array of n values and efficiently process the following types of queries:

1. Increase the first value in range [a,b] by 1, the second value by 2, the third value by 3, and so on.
2. Calculate the sum of values in range [a,b]. 

## Input  
The first input line has two integers n and q: the array size and the number of queries.
The next line has n values t<sub>1</sub>, t<sub>2</sub>,&hellip; t<sub>n</sub>: the initial contents of the array.
Finally, there are q lines describing the queries. The format of each line is either "1 a b" or "2 a b".

## Output
Print the answer to each sum query. 

## Constraints

- 1 &le; n,q &le; 2&times;10<sup>5</sup>
- 1 &le; t<sub>i</sub>, x &le; 10<sup>6</sup>
 - 1 &le; a &le; b &le; n

## Example
<font color="blue">**Input:**</font>
```c++
5 3
4 2 3 1 7
2 1 5
1 1 5
2 1 5
```
<font color="blue">**Output:**</font>
```c++
17
32
``` 
