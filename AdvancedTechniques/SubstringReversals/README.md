# Substring Reversals  

Given a string, your task is to process operations where you reverse a substring of the string. What is the final string after all the operations?

## Input

The first input line has two integers n and m: the length of the string and the number of operations. The characters of the string are numbered 1,2,&hellip;,n.
The next line has a string of length n that consists of characters A–Z.
Finally, there are m lines that describe the operations. Each line has two integers a and b: you reverse a substring from position a to position b.

## Output

Print the final string after all the operations.

## Constraints

* 1 &le; n,m  &le; 2&middot;10<sup>5</sup>
* 1 &le; a &le; b  &le; n

## Example

**Input:**
```c++
7 2
AYBABTU
3 4
4 7
```

**Output:**
```c++
AYAUTBB
```  