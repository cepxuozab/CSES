# Substring Order I

You are given a string of length n. If all of its distinct substrings are ordered lexicographically, what is the kth smallest of them?  

## Input  

The first input line has a string of length n that consists of characters a–z.
The second input line has an integer k.

## Output
Print the kth smallest distinct substring in lexicographical order.  

## Constraints

- 1 &le; n &le; 10<sup>5</sup>
- 1 &le; k &le; n&times;(n+1) &frasl;<sub>2</sub>
- It is guaranteed that k does not exceed the number of distinct substrings.


## Example1
<font color="blue">**Input:**</font> 
```c++
babaacbaab
10
```
<font color="blue">**Output:**</font>
```c++
aba
```  

**Explanation**: The 10 smallest distinct substrings in order are a, aa, aab, aac, aacb, aacba, aacbaa, aacbaab, ab, and aba.
