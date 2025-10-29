# Missing Coin Sum Queries  

You have n coins with positive integer values. The coins are numbered 1,2,&hellip;,n.
Your task is to process q queries of the form: "if you can use coins a &hellip; b, what is the smallest sum you cannot produce?"

## Input

The first input line has two integers n and q: the number of coins and queries.
The second line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the value of each coin.
Finally, there are q lines that describe the queries. Each line has two values a and b: you can use coins a \dots b.

## Output

Print the answer for each query.  

## Constraints

* 1 &le; n, q &le; 2&middot;10<sup>5</sup>  
* 1 &le; x<sub>i</sub> &le; 10<sup>9</sup>  
* 1 &le; a,b &le; n 

## Example

**Input:**
```c++
5 3
2 9 1 2 7
2 4
4 4
1 5
```

**Output:**
```c++
4
1
6
```

## Explanation:

First you can use coins [9,1,2], then coins [2] and finally coins [2,9,1,2,7].