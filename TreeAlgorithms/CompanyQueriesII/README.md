# Company Queries II  

A company has n employees, who form a tree hierarchy where each employee has a boss, except for the general director.
Your task is to process q queries of the form: who is the lowest common boss of employees a and b in the hierarchy?  

## Input  
The first input line has two integers n and q: the number of employees and queries. The employees are numbered 1,2,&hellip;,n, and employee 1 is the general director.
The next line has n-1 integers e<sub>2</sub>,e<sub>3</sub>,&hellip;,e<sub>n</sub>: for each employee 2,3,&hellip;,n their boss.
Finally, there are q lines describing the queries. Each line has two integers a and b: who is the lowest common boss of employees a and b?


## Output
Print the answer for each query. 

## Constraints

- 1 &le; n,q &le; 2 &times; 10<sup>5</sup>
- 1 &le; e_i &le; i-1
- 1 &le; a, b &le; n


## Example1
<font color="blue">**Input:**</font> 
```c++
5 3
1 1 3 3
4 5
2 5
1 4
```
<font color="blue">**Output:**</font>
```c++
3
1
1
```  



