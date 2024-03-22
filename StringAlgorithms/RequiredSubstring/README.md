# Required Substring 

Your task is to calculate the number of strings of length n having a given pattern of length m as their substring. All strings consist of characters A–Z.

## Input 
The first input line has an integer n: the length of the final string.
The second line has a pattern of length m.

## Output
Print the number of strings modulo 10<sup>9</sup> + 7.

## Constraints

- 1 &le; n &le; 1000
- 1 &le; m &le; 100


## Example1
<font color="blue">**Input:**</font> 
```c++
6
ABCDB
```
<font color="blue">**Output:**</font>
```c++
52
```  

**Explanation:** The final string will be of the form ABCDBx or xABCDB where x is any character between A–Z.





