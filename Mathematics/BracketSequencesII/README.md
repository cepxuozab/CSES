# Bracket Sequences II

Your task is to calculate the number of valid bracket sequences of length n when a prefix of the sequence is given.

## Input

The first input line has an integer n.
The second line has a string of k characters: the prefix of the sequence.

## Output

Print the number of sequences modulo 10<sup>9</sup>+7.


## Constraints

- 1 &le; k &le; n &le; 10<sup>6</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
6
(()
```
<font color="blue">**Output:**</font>
```c++
2
``` 

**Explanation**: There are two possible sequences: (())() and (()()).
