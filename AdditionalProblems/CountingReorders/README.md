# Counting Reorders  

Calculate the number of ways you can reorder the characters of a string so that no two adjacent characters are the same.
For example, the answer for aabc is 6, because the possible orders are abac, abca, acab, acba, baca, and caba.

## Input

The only input line has a string that consists of n characters between a–z.

## Output

Print an integer: the answer modulo 10<sup>9</sup>+7.

## Constraints

* 1 &le; n &le; 5000  

## Example

**Input:**
```c++
aabc
```

**Output:**
```c++
6
```
