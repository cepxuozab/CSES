# Range Update Queries
**Time limit:** 1.00 s **Memory limit:** 512 MB  

Given an array of n integers, your task is to process q queries of the following types:

- increase each value in range [a,b] by u
- what is the value at position k?  

## Input  

The first input line has two integers n and q: the number of values and queries.
The second line has n integers: x<sub>1</sub>,x<sub>2</sub>...,x<sub>n</sub>: the contents of the array.
Finally, there are q lines describing the queries. Each line has three integers: either "1 a b u" or "2 k".
## Output

Print the result of each query of type 2  

## Constraints
- 1 <= n, q <= 10<sup>5</sup>
- 1 <= x<sub>i</sub>, u <= 10<sup>9</sup>  
- 1<= k <= n
- 1 <= a <= b <= n
  

## Example
### Input:
```
8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4
```
### Output:
```
5
6
```