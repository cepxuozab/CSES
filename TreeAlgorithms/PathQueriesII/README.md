# Path Queries II

You are given a tree consisting of n nodes. The nodes are numbered 1,2,&hellip;,n. Each node has a value.
Your task is to process following types of queries:

1. change the value of node s to x
2. find the maximum value on the path between nodes a and b.

## Input

The first input line contains two integers n and q: the number of nodes and queries. The nodes are numbered 1,2,&hellip;,n.
The next line has n integers v<sub>1</sub>,v<sub>2</sub>,&hellip;,v<sub>n</sub>: the value of each node.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
Finally, there are q lines describing the queries. Each query is either of the form "1 s x" or "2 s".


## Output  
Print the answer to each query of type 2.

## Constraints  

- 1 ≤ &le; n,q &le;  2 &times; 10<sup>5</sup>
- 1  &le; a, b, s  &le; n
- 1  &le; v<sub>i</sub> ,x  &le; 10<sup>9</sup>

## <span style = "color:blue">Example<span>
**Input:**
```
5 3
2 4 1 3 3
1 2
1 3
2 4
2 5
2 3 5
1 2 2
2 3 5
```
**Output:**
```
4 3
```

