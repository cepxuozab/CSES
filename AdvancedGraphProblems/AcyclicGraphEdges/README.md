# Acyclic Graph Edges  

Given an undirected graph, your task is to choose a direction for each edge so that the resulting directed graph is acyclic.

## Input

The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1,2,&hellip;,n.
After this, there are m lines describing the edges. Each line has two distinct integers a and b: there is an edge between nodes a and b.

## Output

Print m lines describing the directions of the edges. Each line has two integers a and b: there is an edge from node a to node b. You can print any valid solution.

## Constraints

* 1 &le; n &le; 10<sup>5</sup>
* 1 &le; m &le; 2 &middot; 10<sup>5</sup>
* 1 &le; a,b &le; n

## Example1
<font color="blue">**Input:**</font>
```c++
3 3
1 2
2 3
3 1
```
<font color="blue">**Output:**</font>
```c++
1 2
3 2
3 1
``` 