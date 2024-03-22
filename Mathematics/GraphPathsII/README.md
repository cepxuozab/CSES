# Graph Paths II

Consider a directed weighted graph having n nodes and m edges. Your task is to calculate the minimum path length from node 1 to node n with exactly k edges.

## Input

The first input line contains three integers n, m and k: the number of nodes and edges, and the length of the path. The nodes are numbered 1,2,&hellip;,n.
Then, there are m lines describing the edges. Each line contains three integers a, b and c: there is an edge from node a to node b with weight c.

## Output

Print the minimum path length. If there are no such paths, print -1.



## Constraints

* 1 &le; n &le; 100
* 1 &le; m &le; n(n-1)
* 1 &le; k &le; 10<sup>9</sup>
* 1 &le; a,b &le; n
* 1 &le; c &le; 10<sup>9</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
3 4 8
1 2 5
2 3 4
3 1 1
3 2 2
```
<font color="blue">**Output:**</font>
```c++
27
``` 
