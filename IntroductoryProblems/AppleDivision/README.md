# Apple Division 

There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.

## Input
The first input line has an integer n: the number of apples.
The next line has n integers p<sub>1</sub>, p<sub>2</sub>, &hellip;, p<sub>n</sub>: the weight of each apple.

## Output
Print one integer: the minimum difference between the weights of the groups 

## Constraints

- 1 &le; n &le; 20 
- 1 &le; p<sub>i</sub> &le; 10<sup>9</sup>  

## Example1
<font color="blue">**Input:**</font> 
```c++
5
3 2 7 4 1
```
<font color="blue">**Output:**</font>
```c++
1
```  

**Explanation**: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).

