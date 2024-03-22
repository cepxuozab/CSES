# Fixed-Length Paths II

Given a tree of n nodes, your task is to count the number of distinct paths that have at least k<sub>1</sub> and at most k<sub>2</sub> edges.

## Input

The first input line contains three integers n, k<sub>1</sub> and k<sub>2</sub>: the number of nodes and the path lengths. The nodes are numbered 1,2,&hellip;,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.


## Output  
Print one integer: the number of paths.

## Constraints  

- 1 ≤ &le;  k<sub>1</sub> &le; k<sub>2</sub> &le; n  &le;  2 &times; 10<sup>5</sup>
- 1  &le; a, b  &le; n


## <span style = "color:blue">Example<span>
**Input:**
```
5 2 3
1 2
2 3
3 4
3 5
```
**Output:**
```
6
```

