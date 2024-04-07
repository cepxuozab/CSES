# New Flight Routes  

There are n cities and m flight connections between them. Your task is to add new flights so that it will be possible to travel from any city to any other city. What is the minimum number of new flights required?

## Input

The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,&hellip;,n.
After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. All flights are one-way flights.

## Output

First print an integer k: the required number of new flights. After this, print k lines describing the new flights. You can print any valid solution.

## Constraints

* 1 &le; n  &le; 10<sup>5</sup>
* 1 &le; m  &le; 2&middot;10<sup>5</sup>
* 1 &le; a,b  &le; n

## Example

**Input:**
```c++
4 5
1 2
2 3
3 1
1 4
3 4
```

**Output:**
```c++
1
4 2
```  
