# Road Reparation

There are n cities and m roads between them. Unfortunately, the condition of the roads is so poor that they cannot be used. Your task is to repair some of the roads so that there will be a decent route between any two cities.
For each road, you know its reparation cost, and you should find a solution where the total cost is as small as possible  

## Input  
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,&hellip;,n.
Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b, and its reparation cost is c. All roads are two-way roads.
Every road is between two different cities, and there is at most one road between two cities.  

## Output
Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".

## Constraints

- 1 &le; n &le; 10<sup>5</sup>
- - 1 &le; m &le; 2&times;10<sup>5</sup>
- 1 &le; a, b &le; n
- 1 &le; c &le; 10<sup>9</sup>

## Example
<font color="blue">**Input:**</font>
```c++
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
```
<font color="blue">**Output:**</font>
```c++
14
``` 
