# Grid Puzzle II

There is an n &times; n grid whose each square has some number of coins in it.
You know for each row and column how many squares you must choose from that row or column. You get all coins from every square you choose. What is the maximum number of coins you can collect and how could you choose the squares so that the given conditions are satisfied?

## Input

The first input line has an integer n: the size of the grid. The rows and columns are numbered 1,2,&hellip;,n.
The next line has n integers a<sub>1</sub>,a<sub>2</sub>,&hellip;,a<sub>n</sub>: You must choose exactly a<sub>i</sub> squares from the ith row.
The next line has n integers b<sub>1</sub>,b<sub>2</sub>,&hellip;,b<sub>n</sub>: You must choose exactly b<sub>j</sub> squares from the jth column.
Finally, there are n lines describing the grid. You can assume that the sums of a<sub>1</sub>,a<sub>2</sub>,&hellip;,a<sub>n</sub> and b<sub>1</sub>,b<sub>2</sub>,&hellip;,b<sub>n</sub> are equal.

## Output

First print an integer k: the maximum number of coins you can collect. After this print n lines describing which squares you choose (X means that you choose a square, . means that you don't choose it).
If it is not possible to satisfy the conditions print only -1.

## Constraints   

* 1 &le; n &le; 50
* 0 &le; a<sub>i</sub> &le; n
* 0 &le; b<sub>j</sub> &le; n
* 0 &le; c<sub>i,j</sub> &le; 1000

## Example1
<font color="blue">**Input:**</font>
```c++
5
0 1 3 2 0
1 2 2 0 1
2 5 1 5 1
0 2 5 1 2
3 8 9 3 5
1 4 3 7 3
0 3 6 2 8
```
<font color="blue">**Output:**</font>
```c++
32
.....
..X..
.XX.X
XX...
.....
```   

