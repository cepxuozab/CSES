# Pattern Positions 

Given a string and patterns, find for each pattern the first position (1-indexed) where it appears in the string.  

## Input  

The first input line has a string of length n.
The next input line has an integer k: the number of patterns. Finally, there are k lines that describe the patterns.
The string and the patterns consist of characters a–z.

## Output
Print the first position for each pattern (or -1 if it does not appear at all).

## Constraints

- 1 &le; n &le; 10<sup>5</sup>
- 1 &le; k &le; 5&times;10<sup>5</sup>
- the total length of the patterns is at most  5&times;10<sup>5</sup>

## Example1
<font color="blue">**Input:**</font> 
```c++
aybabtu
aybabtu
3
bab
abc
a
```
<font color="blue">**Output:**</font>
```c++
3
-1
1
```  






