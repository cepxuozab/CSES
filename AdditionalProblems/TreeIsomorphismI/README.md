# Swap Round Sorting 

Given two rooted trees, your task is to find out if they are isomorphic, i.e., it is possible to draw them so that they look the same.

## Input

The first input line has an integer t: the number of tests. Then, there are t tests described as follows:
The first line has an integer n: the number of nodes in both trees. The nodes are numbered 1,2,&hellip;,n, and node 1 is the root.
Then, there are n-1 lines describing the edges of the first tree, and finally n-1 lines describing the edges of the second tree.

## Output

For each test, print "YES", if the trees are isomorphic, and "NO" otherwise.

## Constraints

* 1 &le; t &le; 1000
* 1 &le; n &le; 2&middot;10<sup>5</sup>
* the sum of all values of n is at most 10<sup>5</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
2
3
1 2
2 3
1 2
1 3
3
1 2
2 3
1 3
3 2
```
<font color="blue">**Output:**</font>
```c++
NO
YES
```   
