# Food Division 

There are n children around a round table. For each child, you know the amount of food they currently have and the amount of food they want. The total amount of food in the table is correct.
At each step, a child can give one unit of food to his or her neighbour. What is the minimum number of steps needed?

## Input

The first input line contains an integer n: the number of children.
The next line has n integers a<sub>i</sub>,a<sub>2</sub>,&hellip;,a<sub>n</sub>: the current amount of food for each child.
The last line has n integers b<sub>i</sub>,b<sub>2</sub>,&hellip;,b<sub>n</sub>: the required amount of food for each child.

## Output

Print one integer: the minimum number of steps.

## Constraints

* 1 &le; n &le; 2&middot;10<sup>5</sup>
* 1 &le; a<sub>i</sub>, b<sub>i</sub> &le; 10<sup>6</sup>

## Example1
<font color="blue">**Input:**</font>
```c++
3
3 5 0
2 4 2
```
<font color="blue">**Output:**</font>
```c++
2
```   

## Explanation: 

Child 1 gives one unit of food to child 3, and child 2 gives one unit of food to child 3.
