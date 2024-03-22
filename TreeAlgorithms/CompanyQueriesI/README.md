# Company Queries I  

A company has n employees, who form a tree hierarchy where each employee has a boss, except for the general director.
Your task is to process q queries of the form: who is employee x's boss k levels higher up in the hierarchy?  

## Input  
The first input line has two integers n and q: the number of employees and queries. The employees are numbered 1,2,&hellip;,n, and employee 1 is the general director.
The next line has n-1 integers e<sub>2</sub>,e<sub>3</sub>,&hellip;,e<sub>n</sub>: for each employee 2,3,&hellip;,n their boss.
Finally, there are q lines describing the queries. Each line has two integers x and k: who is employee x's boss k levels higher up?


## Output
Print the answer for each query. If such a boss does not exist, print -1.

## Constraints

- 1 &le; n,q &le; 2 &times; 10<sup>5</sup>
- 1 &le; e_i &le; i-1
- 1 &le; x &le; n
- 1 &le; k &le; n



## Example1
<font color="blue">**Input:**</font> 
```c++
5 3
1 1 3 3
4 1
4 2
4 3
```
<font color="blue">**Output:**</font>
```c++
3
1
-1
```  



