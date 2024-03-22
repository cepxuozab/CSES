# Polygon Lattice Points  

Given a polygon, your task is to calculate the number of lattice points inside the polygon and on its boundary. A lattice point is a point whose coordinates are integers.
The polygon consists of n vertices (x<sub>1</sub>,y<sub>1</sub>),(x<sub>2</sub>,y<sub>2</sub>),&hellip;,(x<sub>n</sub>,y<sub>n</sub>). The vertices (x<sub>i</sub>,y<sub>i</sub>) and (x<sub>i+1</sub>,y<sub>i+1</sub>) are adjacent for i=1,2,&hellip;,n-1, and the vertices (x<sub>1</sub>,y<sub>1</sub>) and (x<sub>n</sub>,y<sub>n</sub>) are also adjacent.

## Input  
The first input line has an integer n: the number of vertices.
After this, there are n lines that describe the vertices. The ith such line has two integers x<sub>i</sub> and y<sub>i</sub>.
You may assume that the polygon is simple, i.e., it does not intersect itself.


## Output
Print two integers: the number of lattice points inside the polygon and on its boundary.

## Constraints

- 3  &le; n  &le; 1000 
- -10<sup>9</sup> &le; x<sub>i</sub>, y<sub>i</sub> &le; 10<sup>9</sup>


## Example1
<font color="blue">**Input:**</font> 
```c++
4
1 1
5 3
3 5
1 4
```
<font color="blue">**Output:**</font>
```c++
6 8
```  



