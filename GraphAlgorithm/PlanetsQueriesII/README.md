# Planets Queries II

You are playing a game consisting of n planets. Each planet has a teleport to another planet (or the planet itself).
You have to process q queries of the form: You are now on planet a and want to reach planet b. What is the minimum number of teleportation? 

## Input  
The first input line contains two integers n and q: the number of planets and queries. The planets are numbered 1,2,&hellip;,n.
The second line contains n integers t<sub>1</sub>,t<sub>2</sub>,&hellip;,t<sub>n</sub>: for each planet, the destination of the teleport.
Finally, there are q lines describing the queries. Each line has two integers a and b: you are now on planet a and want to reach planet b.

## Output
For each query, print the minimum number of teleportations. If it is not possible to reach the destination, print -1.

## Constraints

- 1 &le; n, q &le; 2&times;10<sup>5</sup>
- 1 &le; t<sub>i</sub> &le; n
- 1 &le; a, b &le; n


## Example
<font color="blue">**Input:**</font>
```c++
5 3
2 3 2 3 2
1 2
1 3
1 4
```
<font color="blue">**Output:**</font>
```c++
1
2
-1
``` 
