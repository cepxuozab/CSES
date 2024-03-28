# Intersection Points 

Given n horizontal and vertical line segments, your task is to calculate the number of their intersection points.
You can assume that no parallel line segments intersect, and no endpoint of a line segment is an intersection point.

## Input

The first input line has an integer n: the number of line segments.
Then there are n lines describing the line segments. Each line has four integers: x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub> and y<sub>2</sub>: a line segment begins at point (x<sub>1</sub>,y<sub>1</sub>) and ends at point (x<sub>2</sub>,y<sub>2</sub>).

# Output

Print the number of intersection points.

## Constraints

* 1 &le; n &le; 10<sup>5</sup>
* -10<sup>6</sup> &le; x<sub>1</sub> &le; x<sub>2</sub> &le; 10<sup>6</sup>
* -10<sup>6</sup> &le; y<sub>1</sub> &le; y<sub>2</sub> &le; 10<sup>6</sup>
* (x<sub>1</sub>,y<sub>1</sub>) &ne; (x<sub>2</sub>,y<sub>2</sub>)


## Example1
<font color="blue">**Input:**</font>
```c++
3
2 3 7 3
3 1 3 5
6 2 6 6
```
<font color="blue">**Output:**</font>
```c++
2
``` 