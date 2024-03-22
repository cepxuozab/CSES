# Distinct Routes

A game consists of n rooms and m teleporters. At the beginning of each day, you start in room 1 and you have to reach room n.
You can use each teleporter at most once during the game. How many days can you play if you choose your routes optimally?

## Input  
The first input line has two integers n and m: the number of rooms and teleporters. The rooms are numbered 1,2,&hellip;,n.
After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from room a to room b.
There are no two teleporters whose starting and ending room are the same.  

## Output
First print an integer k: the maximum number of days you can play the game. Then, print k route descriptions according to the example. You can print any valid solution.  

## Constraints

- 1 &le; n &le; 500
- 1 &le; m &le; 1000
- 1 &le; a &le; n
- 1 &le; b &le; n

## Example
<font color="blue">**Input:**</font>
```c++
6 7
1 2
1 3
2 6
3 4
3 5
4 6
5 6
```
<font color="blue">**Output:**</font>
```c++
2
3
1 2 6
4
1 3 4 6
``` 
