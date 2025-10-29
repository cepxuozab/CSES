# List of Sums 

List A consists of n positive integers, and list B contains the sum of each element pair of list A.
For example, if A=[1,2,3], then B=[3,4,5], and if A=[1,3,3,3], then B=[4,4,4,6,6,6].
Given list B, your task is to reconstruct list A.

## Input

The first input line has an integer n: the size of list A.
The next line has n*(n-1)/2 integers: the contents of list B.
You can assume that there is a list A that corresponds to the input, and each value in A is between 1 &hellip; k.

## Output

Print n integers: the contents of list A.
You can print the values in any order. If there are more than one solution, you can print any of them.

## Constraints

* 1 &le; n &le; 100
* 1 &le; k &le; 10<sup>9</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
4
4 4 4 6 6 6
```
<font color="blue">**Output:**</font>
```c++
1 3 3 3
```    

## Explanation:  

In this case list A can be either [1,3,3,3] or [2,2,2,4] and both solutions are accepted.