# Dynamic Range Sum Queries 

**Time limit:** 1.00 s **Memory limit:** 512 MB

Given an array of n integers, your task is to process q queries of the following types:

1. update the value at position k to u
2. what is the sum of values in range [a,b]?  

## Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x<sub>1</sub>,x<sub>2</sub>,...,x<sub>n</sub>: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".  
## Output
Print the result of each query of type 2.
## Constraints  
- 1 <= n,q <= 2*10^5
- 1 <= x<sub>i</sub>, u <= 10^9
- 1 <= k <= n
- 1 <= a <= b <= n  

## Example
### Input:
```
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4
```
### Output:
```
14
2
11
```