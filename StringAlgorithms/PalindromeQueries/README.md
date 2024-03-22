# Palindrome Queries 

You are given a string that consists of n characters between a–z. The positions of the string are indexed 1,2,&hellip;,n.
Your task is to process m operations of the following types:

- Change the character at position k to x
- Check if the substring from position a to position b is a palindrome  

## Input 
The first input line has two integers n and m: the length of the string and the number of operations.
The next line has a string that consists of n characters.
Finally, there are m lines that describe the operations. Each line is of the form "1 k x" or "2 a b".

## Output
For each operation 2, print YES if the substring is a palindrome and NO otherwise.

## Constraints

- 1 &le; n,m &le; 2&times;10<sup>5</sup>
- 1 &le; k &le; n
- 1 &le; a &le; b &le; n  

## Example1
<font color="blue">**Input:**</font> 
```c++
7 5
aybabtu
2 3 5
1 3 x
2 3 5
1 5 x
2 3 5
```
<font color="blue">**Output:**</font>
```c++
YES
NO
YES
```  






