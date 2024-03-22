# Salary Queries  

A company has n employees with certain salaries. Your task is to keep track of the salaries and process queries.  

## Input 

The first input line contains two integers n and q: the number of employees and queries. The employees are numbered 1,2,&hellip;,n.
The next line has n integers p<sub>1</sub>,p<sub>2</sub>,&hellip;,p<sub>n</sub>: each employee's salary.
After this, there are q lines describing the queries. Each line has one of the following forms:

- ! k x: change the salary of employee k to x
- ? a b: count the number of employees whose salary is between a &hellip; b

## Output
Print the answer to each ? query.

## Constraints

- 1 &le; n, q &le; 2 &times; 10<sup>5</sup>
- 1 &le; p<sub>i</sub> &le; 10<sup>9</sup>
- 1 &le; k &le; n 
- 1 &le; x &le; 10<sup>9</sup>
- 1 &le; a &le; b &le; 10<sup>9</sup>

## Example1
<font color="blue">**Input:**</font> 
```c++
5 3
3 7 2 2 5
? 2 3
! 3 6
? 2 3
```
<font color="blue">**Output:**</font>
```c++
3
2
```  





