# Reachable Nodes  

A directed graph consists of n nodes and m edges. The edges are numbered 1,2,&hellip;,n.
Your task is to answer q queries of the form "can you reach node b from node a?"

## Input

The first input line has three integers n, m and q: the number of nodes, edges and queries.
Then there are m lines describing the edges. Each line has two distinct integers a and b: there is an edge from node a to node b.
Finally, there are q lines describing the queries. Each line consists of two integers a and b: "can you reach node b from node a?"

## Output

Print the answer for each query: either "YES" or "NO".

## Constraints

* 1 &le; n  &le; 5&middot;10<sup>4</sup>
* 1 &le; m,q  &le; 10<sup>5</sup>

## Example

**Input:**
```c++
4 4 3
1 2
2 3
3 1
4 3
1 3
1 4
4 1
```

**Output:**
```c++
YES
NO
YES
```  