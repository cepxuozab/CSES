# Monster Game II

You are playing a game that consists of n levels. Each level has a monster. On levels 1,2,&hellip;,n-1, you can either kill or escape the monster. However, on level n you must kill the final monster to win the game.
Killing a monster takes sf time where s is the monster's strength and f is your skill factor. After killing a monster, you get a new skill factor  (lower skill factor is better). What is the minimum total time in which you can win the game?

## Input

The first input line has two integers n and x: the number of levels and your initial skill factor.
The second line has n integers s<sub>1</sub>,s<sub>2</sub>,&hellip;,s<sub>n</sub>: each monster's strength.
The third line has n integers f<sub>1</sub>,f<sub>2</sub>,&hellip;,f<sub>n</sub>: your new skill factor after killing a monster.

## Output

Print one integer: the minimum total time to win the game.

## Constraints

* 1 &le; n  &le; 2&middot;10<sup>5</sup>
* 1 &le; x  &le; 10<sup>6</sup>
* 1 &le; s<sub>i</sub>,f<sub>i</sub>&le; 10<sup>6</sup>

## Example

**Input:**
```c++
5 100
50 20 30 90 30
60 20 20 10 90
```

**Output:**
```c++
2600
```  

## Explanation: 

The best way to play is to kill the second and fifth monster.