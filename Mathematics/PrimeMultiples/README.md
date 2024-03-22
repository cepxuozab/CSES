# Prime Multiples

You are given k distinct prime numbers a<sub>1</sub>,a<sub>2</sub>,&hellip;,a<sub>k</sub> and an integer n.
Your task is to calculate how many of the first n positive integers are divisible by at least one of the given prime numbers.

## Input

The first input line has two integers n and k.
The second line has k prime numbers a<sub>1</sub>,a<sub>2</sub>,&hellip;,a<sub>k</sub>.

## Output

Print one integer: the number integers within the interval 1,2,&hellip;,n that are divisible by at least one of the prime numbers.

## Constraints

- 1 &le; n &le; 10<sup>18</sup>
- 1 &le; k &le; 20
- 2 &le; a<sub>i</sub> &le; n

## Example1
<font color="blue">**Input:**</font>
```c++
20 2
2 5
```
<font color="blue">**Output:**</font>
```c++
12
``` 

**Explanation:** the 12 numbers are 2,4,5,6,8,10,12,14,15,16,18,20.