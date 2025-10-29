# Bit Inversions

There is a bit string consisting of n bits. Then, there are some changes that invert one given bit. Your task is to report, after each change, the length of the longest substring who's each bit is the same.

## Input

The first input line has a bit string consisting of n bits. The bits are numbered 1,2,&hellip;,n.
The next line contains an integer m: the number of changes.
The last line contains m integers x<sub>1</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub> describing the changes.

## Output

After each change, print the length of the longest substring who's each bit is the same.

## Constraints

* 1 &le; n &le; 2&middot;10<sup>5</sup>
* 1 &le; m &le; 2&middot;10<sup>5</sup>
* 1 &le; x<sub>i</sub> &le; n

## Example1
<font color="blue">**Input:**</font>
```c++
001011
3
3 2 5
```
<font color="blue">**Output:**</font>
```c++
4 2 3
``` 

## Explanation:
The bit string first becomes 000011, then 010011, and finally 010001.