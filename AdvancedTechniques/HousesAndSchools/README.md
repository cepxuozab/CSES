# Houses and Schools

There are n houses on a street, numbered 1,2,&hellip;,n. The distance of houses a and b is |a-b|. You know the number of children in each house.
Your task is to establish k schools in such a way that each school is in some house. Then, each child goes to the nearest school. What is the minimum total walking distance of the children if you act optimally?

## Input

The first input line has two integers n and k: the number of houses and the number of schools. The houses are numbered 1,2&hellip;,n.
After this, there are n integers c<sub>1</sub>,c<sub>2</sub>,&hellip;,c<sub>n</sub>: the number of children in each house.

## Output

Print the minimum total distance.

## Constraints

* 1 &le; k &le; n  &le; 3000
* 1 &le; c<sub>i</sub>  &le; 10<sup>5</sup>


## Example

**Input:**
```c++
6 2
2 7 1 4 6 4
```

**Output:**
```c++
11
```  

## Explanation: 

Houses 2 and 5 will have schools.