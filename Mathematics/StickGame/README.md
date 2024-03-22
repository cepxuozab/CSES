# Stick Game

Consider a game where two players remove sticks from a heap. The players move alternately, and the player who removes the last stick wins the game.
A set P={p<sub>1</sub>,p<sub>2</sub>,&hellip;,p<sub>k</sub>} determines the allowed moves. For example, if P={1,3,4}, a player may remove 1, 3 or 4 sticks.
Your task is find out for each number of sticks 1,2,&hellip;,n if the first player has a winning or losing position.

## Input

The first input line has two integers n and k: the number of sticks and moves.
The next line has k integers p<sub>1</sub>,p<sub>2</sub>,\&hellip;,p<sub>k</sub> that describe the allowed moves. All integers are distinct, and one of them is 1.

## Output

Print a string containing n characters: W means a winning position, and L means a losing position


## Constraints

* 1 &le; n &le; 10<sup>9</sup>
* 1 &le; k &le; 100
* 1 &le; p<sub>i</sub> &le; n


## Example1
<font color="blue">**Input:**</font>
```c++
10 3
1 3 4
```
<font color="blue">**Output:**</font>
```c++
WLWWWWLWLW
``` 
