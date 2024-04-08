# Signal Processing

You are given two integer sequences: a signal and a mask. Your task is to process the signal by moving the mask through the signal from left to right. At each mask position calculate the sum of products of aligned signal and mask values in the part where the signal and the mask overlap.

## Input

The first input line consists of two integers n and m: the length of the signal and the length of the mask.
The next line consists of n integers a<sub>1</sub>,a<sub>2</sub>,&hellip;,a<sub>n</sub> defining the signal.
The last line consists of m integers b<sub>1</sub>,b<sub>2</sub>,&hellip;,b<sub>m</sub> defining the mask.

## Output

Print n+m-1 integers: the sum of products of aligned values at each mask position from left to right. 

## Constraints

* 1 &le;  n,m  &le; 2&middot;10<sup>5</sup>
* 1 &le; a<sub>i</sub>, b<sub>i</sub> &le; 100

## Example

**Input:**
```c++
5 3
1 3 2 1 4
1 2 3
```

**Output:**
```c++
3 11 13 10 16 9 4
```  

## Explanation:

For example, at the second mask position the sum of aligned products is 2 &middot; 1 + 3 &middot; 3 = 11.
