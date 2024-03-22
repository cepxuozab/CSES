# Point Location Test

There is a line that goes through the points p<sub>1</sub>=(x<sub>1</sub>,y<sub>1</sub>) and p<sub>2</sub>=(x<sub>2</sub>,y<sub>2</sub>). There is also a point p<sub>3</sub>=(x<sub>3</sub>,y<sub>3</sub>).
Your task is to determine whether p<sub>3</sub> is located on the left or right side of the line or if it touches the line when we are looking from p<sub>1</sub> to p<sub>2</sub>.You are given a description of a path which may also contain characters ? (any direction). Your task is to calculate the number of paths that match the description.  

## Input
The first input line has an integer t: the number of tests.
After this, there are t lines that describe the tests. Each line has six integers: x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub>, y<sub>2</sub>, x<sub>3</sub> and y<sub>3</sub>.

## Output
For each test, print "LEFT", "RIGHT" or "TOUCH".

## Constraints

- 1 &le; t &le; 10<sup>5</sup>
- -10<sup>9</sup> &le; x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub>, y<sub>2</sub>, x<sub>3</sub>, y<sub>3</sub> &le; 10<sup>9</sup>
- x<sub>1</sub> &ne; x<sub>2</sub> or y<sub>1</sub> &ne; y<sub>2</sub>  

## Example1
<font color="blue">**Input:**</font> 
```c++
3
1 1 5 3 2 3
1 1 5 3 4 1
1 1 5 3 3 2
```
<font color="blue">**Output:**</font>
```c++
LEFT
RIGHT
TOUCH
```  



