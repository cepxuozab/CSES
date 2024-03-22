# Line Segment Intersection  

There are two line segments: the first goes through the points (x<sub>1</sub>,y<sub>1</sub>) and (x<sub>2</sub>,y<sub>2</sub>), and the second goes through the points (x<sub>3</sub>,y<sub>3</sub>) and (x<sub>4</sub>,y<sub>4</sub>).
Your task is to determine if the line segments intersect, i.e., they have at least one common point.

## Input
The first input line has an integer t: the number of tests.
After this, there are t lines that describe the tests. Each line has eight  integers: x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub>, y<sub>2</sub>, x<sub>3</sub>, y<sub>3</sub>, x<sub>4</sub> and y<sub>4</sub>.

## Output
For each test, print "YES" if the line segments intersect and "NO" otherwise.

## Constraints

- 1 &le; t &le; 10<sup>5</sup>
- -10<sup>9</sup> &le; x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub>, y<sub>2</sub>, x<sub>3</sub>, y<sub>3</sub>, x<sub>4</sub>, y<sub>4</sub> &le; 10<sup>9</sup>
- (x<sub>1</sub>,y<sub>1</sub>) &ne; (x<sub>2</sub>,y<sub>2</sub>)  
- (x<sub>3</sub>,y<sub>3</sub>) &ne; (x<sub>4</sub>,y<sub>4</sub>)  

## Example1
<font color="blue">**Input:**</font> 
```c++
5
1 1 5 3 1 2 4 3
1 1 5 3 1 1 4 3
1 1 5 3 2 3 4 1
1 1 5 3 2 4 4 1
1 1 5 3 3 2 7 4
```
<font color="blue">**Output:**</font>
```c++
NO
YES
YES
YES
YES
```  



