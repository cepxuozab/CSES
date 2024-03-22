# Planets Cycles

You are playing a game consisting of n planets. Each planet has a teleport to another planet (or the planet itself).
You start on a planet and then travel through teleports until you reach a planet that you have already visited before.
Your task is to calculate for each planet the number of teleportation there would be if you started on that planet.  

## Input  
The first input line has an integer n: the number of planets. The planets are numbered 1,2,&hellip;,n.
The second line has n integers t<sub>1</sub>,t<sub>2</sub>,&hellip;,t<sub>n</sub>: for each planet, the destination of the teleport. It is possible that t<sub>i</sub>=i.

## Output
Print n integers according to the problem statement.

## Constraints

- 1 &le; n &le; 2&times;10<sup>5</sup>
- 1 &le; t<sub>i</sub> &le; n


## Example
<font color="blue">**Input:**</font>
```c++
5
2 4 3 1 4
```
<font color="blue">**Output:**</font>
```c++
3 3 1 3 4
``` 
