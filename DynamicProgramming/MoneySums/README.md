# Money Sums

You have n coins with certain values. Your task is to find all money sums you can create using these coins.

## Input

The first input line has an integer n: the number of coins.
The next line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the values of the coins.

## Output

First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.


## Constraints

- 1 &le; n &le; 100
- 1 x<sub>i</sub> &le; 1000

## Example1
<font color="blue">**Input:**</font>
```c++
4
4 2 5 2
```
<font color="blue">**Output:**</font>
```c++
9
2 4 5 6 7 8 9 11 13
``` 
