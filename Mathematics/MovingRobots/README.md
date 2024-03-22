# Moving Robots

Each square of an 8 &times; 8 chessboard has a robot. Each robot independently moves k steps, and there can be many robots on the same square.
On each turn, a robot moves one step left, right, up or down, but not outside the board. It randomly chooses a direction among those where it can move.
Your task is to calculate the expected number of empty squares after k turns.

## Input

The only input line has an integer k.

## Output

Print the expected number of empty squares rounded to six decimal places (rounding half to even).



## Constraints

* 1 &le; k &le; 100


## Example1
<font color="blue">**Input:**</font>
```c++
10
```
<font color="blue">**Output:**</font>
```c++
23.120740
``` 
