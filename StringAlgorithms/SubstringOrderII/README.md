# Substring Order II

You are given a string of length n. If all of its substrings (not necessarily distinct) are ordered lexicographically, what is the kth smallest of them?  

## Input  

The first input line has a string of length n that consists of characters a–z.
The second input line has an integer k.

## Output
Print the kth smallest distinct substring in lexicographical order.  

## Constraints

- 1 &le; n &le; 10<sup>5</sup>
- 1 &le; k &le; n&times;(n+1) &frasl;<sub>2</sub>


## Example1
<font color="blue">**Input:**</font> 
```c++
baabaa
10
```
<font color="blue">**Output:**</font>
```c++
ab
```  

**Explanation**: The 10 smallest substrings in order are a, a, a, a, aa, aa, aab, aaba, aabaa, and ab.
