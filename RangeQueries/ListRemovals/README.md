# List Removals  

You are given a list consisting of n integers. Your task is to remove elements from the list at given positions, and report the removed elements.

## Input  
The first input line has an integer n: the initial size of the list. During the process, the elements are numbered 1,2,&hellip;,k where k is the current size of the list.
The second line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the contents of the list.
The last line has n integers p<sub>1</sub>,p<sub>2</sub>,&hellip;,p<sub>n</sub>: the positions of the elements to be removed.

## Output
Print the elements in the order they are removed. 

## Constraints

- 1 &le; n &le; 2 &times; 10<sup>5</sup>
- 1 &le; x<sub>i</sub> &le; 10<sup>9</sup>
- 1 &le; p<sub>i</sub> &le; n - i +1


## Example1
<font color="blue">**Input:**</font> 
```c++
5
2 6 1 4 2
3 1 3 1 1
```
<font color="blue">**Output:**</font>
```c++
1 2 2 6 4
```  

**Explanation**: The contents of the list are [2,6,1,4,2], [2,6,4,2], [6,4,2], [6,4], [4] and [].



