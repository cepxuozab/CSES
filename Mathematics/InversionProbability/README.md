# Inversion Probability

An array has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>, and each of them has been randomly chosen between 1 and r<sub>i</sub>. An inversion is a pair (a,b) where a < b and x<sub>a</sub> > x<sub>b</sub>.
What is the expected number of inversions in the array?

## Input

The first input line contains an integer n: the size of the array.
The second line contains n integers r<sub>1</sub>,r<sub>2</sub>,&hellip;,r<sub>n</sub>: the range of possible values for each array position.

## Output

Print the expected number of inversions rounded to six decimal places (rounding half to even).

## Constraints

* 1 &le; n, r<sub>i</sub> &le; 100


## Example1
<font color="blue">**Input:**</font>
```c++
3
5 2 7
```
<font color="blue">**Output:**</font>
```c++
1.057143
``` 
