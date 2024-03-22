# Range Updates and Sums

Your task is to maintain an array of n values and efficiently process the following types of queries:

1. Increase each value in range [a,b] by x.
2. Set each value in range [a,b] to x.
3. Calculate the sum of values in range [a,b].  

## Input  
The first input line has two integers n and q: the array size and the number of queries.
The next line has n values t<sub>1</sub>, t<sub>2</sub>,&hellip; t<sub>n</sub>: the initial contents of the array.
Finally, there are q lines describing the queries. The format of each line is one of the following: "1 a b x",  "2 a b x", or "3 a b".

## Output
Print the answer to each sum query. 

## Constraints

- 1 &le; n,q &le; 2&times;10<sup>5</sup>
- 1 &le; t<sub>i</sub>, x &le; 10<sup>6</sup>
 - 1 &le; a &le; b &le; n

## Example
<font color="blue">**Input:**</font>
```c++
6 5
2 3 1 1 5 3
3 3 5
1 2 4 2
3 3 5
2 2 4 5
3 3 5
```
<font color="blue">**Output:**</font>
```c++
7
11
15
``` 
