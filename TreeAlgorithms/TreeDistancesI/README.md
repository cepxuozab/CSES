# Tree Distances I  

You are given a tree consisting of n nodes.
Your task is to determine for each node the maximum distance to another node.  

## Input  
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,&hellip;,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.


## Output
Print n integers: for each node 1,2,&hellip;,n, the maximum distance to another node.

## Constraints

- 1  &le; n  &le; 2&times;10<sup>5</sup> 
- 1 &le; a, b &le; n


## Example1
<font color="blue">**Input:**</font> 
```c++
5
1 2
1 3
3 4
3 5
```
<font color="blue">**Output:**</font>
```c++
2 3 2 3 3
```  



