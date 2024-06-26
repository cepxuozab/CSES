# Nested Ranges Check
**Time limit:** 1.00 s **Memory limit:** 512 MB  

Given n ranges, your task is to determine for each range if it contains some other range and if some other range contains it.
Range [a,b] contains range [c,d] if a <= c and d <= b.  

## Input  

The first input line has an integer n: the number of ranges.
After this, there are n lines that describe the ranges. Each line has two integers x and y: the range is [x,y].
You may assume that no range appears more than once in the input.  

## Output

First print a line that describes for each range (in the input order) if it contains some other range (1) or not (0).

Then print a line that describes for each range (in the input order) if some other range contains it (1) or not (0).


## Constraints
- 1 <= n <= 10<sup>5</sup>
- 1 <= x < y <= 10<sup>9</sup>
  

## Example
### Input:
```
4
1 6
2 4
4 8
3 6
```
### Output:
```
1 0 0 0
0 1 0 1
```