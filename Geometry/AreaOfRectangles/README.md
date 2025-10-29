# Area of Rectangles  

Given n rectangles, your task is to determine the total area of their union.

## Input

The first input line has an integer n: the number of rectangles.
After that, there are n lines describing the rectangles. Each line has four integers x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub> and y<sub>2</sub>: a rectangle begins at point (x<sub>1</sub>,y<sub>1</sub>) and ends at point (x<sub>2</sub>,y<sub>2</sub>).

## Output

Print the total area covered by the rectangles.

## Constraints

* 1 &le; n  &le; 10<sup>5</sup>
* -10<sup>6</sup> &le; x<sub>1</sub> &lt; x<sub>2</sub>  &le; 10<sup>6</sup>
* -10<sup>6</sup> &le; y<sub>1</sub> &lt; y<sub>2</sub>  &le; 10<sup>6</sup>





## Example

**Input:**
```c++
3
1 3 4 5
3 1 7 4
5 3 8 6
```

**Output:**
```c++
24
```  
