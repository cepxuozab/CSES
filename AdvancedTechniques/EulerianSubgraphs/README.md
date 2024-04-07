# Eulerian Subgraphs 

You are given an undirected graph that has n nodes and m edges.
We consider sub graphs that have all nodes of the original graph and some of its edges. A subgraph is called Eulerian if each node has even degree.
Your task is to count the number of Eulerian sub-graphs modulo 10<sup>9</sup>+7.

## Input

The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1,2,&hellip;,n.
After this, there are m lines that describe the edges. Each line has two integers a and b: there is an edge between nodes a and b. There is at most one edge between two nodes, and each edge connects two distinct nodes.

## Output

Print the number of Eulerian sub graphs modulo 10<sup>9</sup>+7.

## Constraints

* 1 &le; n  &le; 10<sup>4</sup>
* 1 &le; m  &le; 2&middot;10<sup>5</sup>
* 1 &le; a, b &le; n

## Example

**Input:**
```c++
4 3
1 2
1 3
2 3
```

**Output:**
```c++
2
```  

## Explanation: 

You can either keep or remove all edges, so there are two possible Eulerian sub-graphs.