# Special Substrings  

A substring is called special if every character that appears in the string appears the same number of times in the substring.
Your task is to count the number of special substrings in a given string.

## Input

The only input line has a string of length n. Every character is between a...z.

## Output

Print one integer: the number of special substrings.

## Constraints

* 1 &le; n &le; 2&middot;10<sup>5</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
abccabab
```
<font color="blue">**Output:**</font>
```c++
5
``` 

<font color="blue">**Explanation**:</font> The special substrings are abc, cab, abccab, bccaba and ccabab.