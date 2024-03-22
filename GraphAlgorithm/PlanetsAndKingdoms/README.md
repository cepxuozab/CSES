# Planets and Kingdoms

A game has n planets, connected by m teleports. Two planets a and b belong to the same kingdom exactly when there is a route both from a to b and from b to a. Your task is to determine for each planet its kingdom.  

## Input  
The first input line has two integers n and m: the number of planets and teleports. The planets are numbered 1,2,&hellip;,n.
After this, there are m lines describing the teleports. Each line has two integers a and b: you can travel from planet a to planet b through a teleport. 

## Output
First print an integer k: the number of kingdoms. After this, print for each planet a kingdom label between 1 and k. You can print any valid solution.  

## Constraints

- 1 &le; n &le; 10<sup>5</sup>
- 1 &le; a, b &le; n
- 1 &le; m &le; 2&times;10<sup>5</sup>  
- 
## Example
<font color="blue">**Input:**</font>
```c++
5 6
1 2
2 3
3 1
3 4
4 5
5 4
```
<font color="blue">**Output:**</font>
```c++
2
1 1 1 2 2
``` 
