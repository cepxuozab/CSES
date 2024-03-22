# Forest Queries II
**Time limit:** 1.00 s **Memory limit:** 512 MB  

You are given an n \times n grid representing the map of a forest. Each square is either empty or has a tree. Your task is to process q queries of the following types:

- Change the state (empty/tree) of a square.
- How many trees are inside a rectangle in the forest?  
- 
## Input  

The first input line has two integers n and q: the size of the forest and the number of queries.
Then, there are n lines describing the forest. Each line has n characters: . is an empty square and * is a tree.
Finally, there are q lines describing the queries. The format of each line is either "1 y x" or "2 y_1 x_1 y_2 x_2".

## Output

Print the answer to each query of the second type  

## Constraints  

- 1 <= n <= 1000
- 1 <= q <= 2* 10^5
- 1 <= y_1 <= y_2 <= n
- 1 <= x_1 <= x_2 <= n
  

## Example
### Input:
```
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2
```
### Output:
```
3
1
2
```