# Grid Puzzle I

There is an n &times; n grid, and your task is to choose from each row and column some number of squares. How can you do that?

## Input

The first input line has an integer n: the size of the grid. The rows and columns are numbered 1,2,&hellip;,n.
The next line has n integers a<sub>1</sub>,a<sub>2</sub>,&hellip;,a<sub>n</sub>: You must choose exactly a<sub>i</sub> squares from the ith row.
The las line has n integers b<sub>1</sub>,b<sub>2</sub>,&hellip;,b<sub>n</sub>: You must choose exactly b<sub>j</sub> squares from the jth column.

## Output

Print n lines describing which squares you choose (X means that you choose a square, . means that you don't choose it). You can print any valid solution.
If it is not possible to satisfy the conditions print only -1.

## Constraints   

* 1 &le; n &le; 50
* 0 &le; a<sub>i</sub> &le; n
* 0 &le; b<sub>j</sub> &le; n

## Example1
<font color="blue">**Input:**</font>
```c++
5
0 1 3 2 0
1 2 2 0 1
```
<font color="blue">**Output:**</font>
```c++
.....
..X..
.XX.X
XX...
.....
```   

