# Critical Cities 

There are n cities and m flight connections between them. A city is called a critical city if it appears on every route from a city to another city.
Your task is to find all critical cities from Syrjälä to Lehmälä.

## Input

The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,&hellip;,n. City 1 is Syrjälä, and city n is Lehmälä.
Then, there are m lines describing the connections. Each line has two integers a and b: there is a flight from city a to city b. All flights are one-way.
You may assume that there is a route from Syrjälä to Lehmälä.

## Output

First print an integer k: the number of critical cities. After this, print k integers: the critical cities in increasing order.

## Constraints

* 2 &le; n &le; 10<sup>5</sup>
* 1 &le; m &le; 2&middot;10<sup>5</sup>
* 1 &le; a, b &le; n

## Example1
<font color="blue">**Input:**</font>
```c++
5 5
1 2
2 3
2 4
3 5
4 5
```
<font color="blue">**Output:**</font>
```c++
3
1 2 5
```   
