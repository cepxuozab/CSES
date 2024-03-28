# Chess Tournament 

There will be a chess tournament of n players. Each player has announced the number of games they want to play.
Each pair of players can play at most one game. Your task is to determine which games will be played so that everybody will be happy.

## Input

The first input line has an integer n: the number of players. The players are numbered 1,2,&hellip;,n.
The next line has n integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: for each player, the number of games they want to play.

## Output

First print an integer k: the number of games. Then, print k lines describing the games. You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".

## Constraints

* 1 &le; n &le; 10<sup>5</sup>
* x<sub>1</sub> + x<sub>2</sub> + &hellip; + x<sub>n</sub> &le; 2&middot;10<sup>5</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
5
1 3 2 0 2
```
<font color="blue">**Output:**</font>
```c++
4
1 2
2 3
2 5
3 5
``` 