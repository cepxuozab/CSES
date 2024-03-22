# Range Queries and Copies

Your task is to maintain a list of arrays which initially has a single array. You have to process the following types of queries:

1. Set the value a in array k to x.
2. Calculate the sum of values in range [a,b] in array k.
3. Create a copy of array k and add it to the end of the list. 

## Input  
The first input line has two integers n and q: the array size and the number of queries.
The next line has n values t<sub>1</sub>, t<sub>2</sub>,&hellip; t<sub>n</sub>: the initial contents of the array.
Finally, there are q lines describing the queries. The format of each line is one of the following: "1 k a x", "2 k a b" or "3 k".

## Output
Print the answer to each sum query. 

## Constraints

- 1 &le; n,q &le; 2&times;10<sup>5</sup>
- 1 &le; t<sub>i</sub>, x &le; 10<sup>9</sup>
 - 1 &le; a &le; b &le; n

## Example
<font color="blue">**Input:**</font>
```c++
5 6
2 3 1 2 5
3 1
2 1 1 5
2 2 1 5
1 2 2 5
2 1 1 5
2 2 1 5
```
<font color="blue">**Output:**</font>
```c++
13
13
13
15
``` 
