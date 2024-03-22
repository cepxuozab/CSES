# Weird Algorithm

Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:  
<div style="text-align: center;">3 &rarr; 10 &rarr; 5 &rarr; 16 &rarr; 8 &rarr; 4 &rarr; 2 &rarr;1</div>   
Your task is to simulate the execution of the algorithm for a given value of n.

## Input
The only input line contains an integer n.
## Output
Print a line that contains all values of n during the algorithm.
## Constraints

- 1 &le; n &le; 10<sup>6</sup>

## Example
<font color="blue">**Input:**</font> 
```c++
3
```
<font color="blue">**Output:**</font>
```c++
3 10 5 16 8 4 2 1
```
