# Reversals and Sums  

Given an array of n integers, you have to process following operations:

reverse a subarray
calculate the sum of values in a subarray

## Input

The first input line has two integers n and m: the size of the array and the number of operations. The array elements are numbered 1,2,&hellip;,n.
The next line as n integers x<sub>i</sub>,x<sub>2</sub>,&hellip;,x<sub>n</sub>: the contents of the array.
Finally, there are m lines that describe the operations. Each line has three integers t, a and b. If t=1, you should reverse a subarray from a to b. If t=2, you should calculate the sum of values from a to b.

## Output

Print the answer to each operation where t=2.

## Constraints

* 1 &le; n  &le; 5&middot;10<sup>4</sup>
* 1 &le; m  &le; 10<sup>5</sup>
* 1 &le; x<sub>i</sub>  &le; 10<sup>9</sup>
* 1 &le; a &le; b &le; 10<sup>9</sup>

## Example

**Input:**
```c++
8 3
2 1 3 4 5 3 4 4
2 2 4
1 3 6
2 2 4
```

**Output:**
```c++
8
9
```  