# Coin Combinations I

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:

* 2+2+5
* 2+5+2
* 5+2+2
* 3+3+3
* 2+2+2+3  
* 2+2+3+2
* 2+3+2+2
* 3+2+2+2  

## Input  
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c<sub>1</sub>,c<sub>2</sub>,&hellip;,c<sub>n</sub>: the value of each coin.

## Output
Print one integer: the number of ways modulo 10<sup>9</sup>+7.

## Constraints

- 1 &le; n &le; 100
- 1 &le; x &le; 10<sup>6</sup>
- 1 &le; c<sub>1</sub> &le; 10<sup>6</sup>

## Example
<font color="blue">**Input:**</font>
```c++
3 9
2 3 5
```
<font color="blue">**Output:**</font>
```c++
8
``` 
