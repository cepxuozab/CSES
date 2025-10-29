# Inverse Inversions

Your task is to create a permutation of numbers 1,2,&hellip;,n that has exactly k inversions.
An inversion is a pair (a,b) where a &lt; b and p<sub>a</sub> &gt; p<sub>b</sub> where p<sub>i</sub> denotes the number at position i in the permutation.

# Input

The only input line has two integers n and k.

## Output

Print a line that contains the permutation. You can print any valid solution.

## Constraints

* 1 &le; n &le; 10<sup>6</sup>
* 1 &le; k &le; n&middot;(n-1)/2


## Example1
<font color="blue">**Input:**</font>
```c++
5 4
```
<font color="blue">**Output:**</font>
```c++
1 5 2 4 3
``` 