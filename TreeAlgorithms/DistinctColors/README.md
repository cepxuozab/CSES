# Distinct Colors
**Time limit:** 1.00 s **Memory limit:** 512 MB  

You are given a rooted tree consisting of n nodes. The nodes are numbered 1,2,...,n, and node 1 is the root. Each node has a color.
Your task is to determine for each node the number of distinct colors in the subtree of the node.
## Input
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,...,n.
The next line consists of n integers c_1,c_2,...,c_n: the color of each node.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
## Output
Print n integers: for each node 1,2,...,n, the number of distinct colors. 

## Constraints  

- 1 <= n <= 2* 10^5
- 1 <= a, b <= n
- 1 <= c_i <= 10^9
  

## Example
### Input:
```
5
2 3 2 2 1
1 2
1 3
3 4
3 5
```
### Output:
```
3 1 2 1 1
```