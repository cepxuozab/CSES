# Flight Route Requests  

There are n cities with airports but no flight connections. You are given m requests which routes should be possible to travel.
Your task is to determine the minimum number of one-way flight connections which makes it possible to fulfil all requests.

## Input

The first input line has two integers n and m: the number of cities and requests. The cities are numbered 1,2,&hellip;,n.
After this, there are m lines describing the requests. Each line has two integers a and b: there has to be a route from city a to city b. Each request is unique.

## Output

Print one integer: the minimum number of flight connections.



## Constraints

* 1 &le; n  &le; 10<sup>5</sup> 
* 1 &le; m  &le; 2&middot;10<sup>5</sup> 
* 1 &le; a,b &le; n 


## Example

**Input:**
```c++
4 5
1 2
2 3
2 4
3 1
3 4
```

**Output:**
```c++
4
```  

## Explanation:

You can create the connections 1 &rightarrow; 2, 2 &rightarrow; 3, 2 &rightarrow; 4 and 3 &rightarrow; 1. Then you can also fly from city 3 to city 4 using the route 3 &rightarrow; 1 &rightarrow; 2 &rightarrow; 4.