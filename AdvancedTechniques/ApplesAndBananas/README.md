# Apples and Bananas

There are n apples and m bananas, and each of them has an integer weight between 1 &hellip; k. Your task is to calculate, for each weight w between 2 &hellip; 2k, the number of ways we can choose an apple and a banana whose combined weight is w.

## Input

The first input line contains three integers k, n and m: the number k, the number of apples and the number of bananas.
The next line contains n integers a<sub>1</sub>,a<sub>2</sub>,&hellip;,a<sub>n</sub>: weight of each apple.
The last line contains m integers b<sub>1</sub>,b<sub>2</sub>,&hellip;,b<sub>m</sub>: weight of each banana.

## Output

For each integer w between 2 &hellip; 2k print the number of ways to choose an apple and a banana whose combined weight is w.  

## Constraints

* 1 &le;   k,n,m  &le; 2&middot;10<sup>5</sup>
* 1 &le; a<sub>i</sub>  &le; k
* 1 &le; b<sub>i</sub>  &le; k


## Example

**Input:**
```c++
5 3 4
5 2 5
4 3 2 3
```

**Output:**
```c++
0 0 1 2 1 2 4 2 0 
```  

## Explanation:

For example for w = 8 there are 4 different ways: we can pick an apple of weight 5 in two different ways and a banana of weight 3 in two different ways.