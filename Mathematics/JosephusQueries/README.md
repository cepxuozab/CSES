# Josephus Queries

Consider a game where there are n children (numbered 1,2,&dots;,n) in a circle. During the game, every second child is removed from the circle, until there are no children left.
Your task is to process q queries of the form: "when there are n children, who is the kth child that will be removed?"

## Input

The first input line has an integer q: the number of queries.
After this, there are q lines that describe the queries. Each line has two integers n and k: the number of children and the position of the child.

## Output

Print q integers: the answer for each query.

## Constraints

- 1 &le; q &le; 10<sup>5</sup>
1 &le; k &le; n &le; 10<sup>9</sup>  

## Example1
<font color="blue">**Input:**</font>
```c++
4
7 1
7 3
2 2
1337 1313
```
<font color="blue">**Output:**</font>
```c++
2
6
1
1107
``` 

