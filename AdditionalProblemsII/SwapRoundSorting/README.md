# Swap Round Sorting 

You are given an array containing a permutation of numbers 1,2,&hellip;,n, and your task is to sort the array using swap rounds. On each swap round, you can choose any number of distinct pairs of elements and swap each pair.
Your task is to find the minimum number of rounds and show how you can choose the pairs in each round.

## Input

The first input line has an integer n: the size of the array.
The second line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the initial permutation.

## Output

First print an integer k: the minimum number of rounds.
Then, for each round, print the number of swaps and the indices of each swap. You can print any valid solution.

## Constraints

1 &le; n &le; 2&middot;10<sup>5</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
5
5 2 1 3 4
```
<font color="blue">**Output:**</font>
```c++
2
2
1 3
4 5
1
3 5
```   

## Explanation: 
The inital array is [5,2,1,3,4]. After round 1, the array becomes [1,2,5,4,3]. After round 2, the array becomes [1,2,3,4,5].
