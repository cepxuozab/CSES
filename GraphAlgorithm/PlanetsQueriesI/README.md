# Planets Queries I

You are playing a game consisting of n planets. Each planet has a teleporter to another planet (or the planet itself).
Your task is to process q queries of the form: when you begin on planet x and travel through k teleports, which planet will you reach? 

## Input  
The first input line has two integers n and q: the number of planets and queries. The planets are numbered 1,2,&hellip;,n.
The second line has n integers t<sub>1</sub>,t<sub>2</sub>,&hellip;,t<sub>n</sub>: for each planet, the destination of the teleported. It is possible that t<sub>i</sub>=i.
Finally, there are q lines describing the queries. Each line has two integers x and k: you start on planet x and travel through k teleports.  

## Output
Print the answer to each query.

## Constraints

- 1 &le; n, q &le; 2&times;10<sup>5</sup>
- 1 &le; t<sub>i</sub>, x &le; n
- 1 &le; k &le; 10<sup>9</sup>

## Example
<font color="blue">**Input:**</font>
```c++
4 3
2 1 1 4
1 2
3 4
4 1
```
<font color="blue">**Output:**</font>
```c++
1
2
4
``` 
