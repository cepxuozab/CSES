# Necessary Roads 

There are n cities and m roads between them. There is a route between any two cities.
A road is called necessary if there is no route between some two cities after removing that road. Your task is to find all necessary roads.

## Input

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,&hellip;,n.
After this, there are m lines that describe the roads. Each line has two integers a and b: there is a road between cities a and b. There is at most one road between two cities, and every road connects two distinct cities.

## Output

First print an integer k: the number of necessary roads. After that, print k lines that describe the roads. You may print the roads in any order.

## Constraints

* 1 &le; n  &le; 5&middot;10<sup>4</sup>
* 1 &le; m  &le; 10<sup>5</sup>
* 1 &le; a, b &le; 10<sup>9</sup>

## Example

**Input:**
```c++
5 5
1 2
1 4
2 4
3 5
4 5
```

**Output:**
```c++
2
3 5
4 5
```  