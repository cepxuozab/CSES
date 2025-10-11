# Sliding Window Minimum

* Time limit: 1.00 s
* Memory limit: 512 MB

You are given an array of n integers. Your task is to calculate the minimum of each window of k elements, from left to
right.
In this problem the input data is large, and it is created using a generator.

### Input

The first line contains two integers n and k: the number of elements and the size of the window.
The next line contains four integers x, a, b and c: the input generator parameters. The input is generated as follows:

* x<sub>1</sub>=x
* x<sub>i</sub>=(a<sub>x<sub>i</sub></sub>+b) % c for i=2,3,&hellip;,n

### Output

Print the xor of all window minimums.

### Constraints

* 1 &le; k &le; n &le; 10<sup>7</sup>
* 0 &le; x, a, b &le; 10<sup>9</sup>
* 1 &le; c &le; 10<sup>9</sup>

## Example

<font color="blue">**Input:**</font>

```c++
8 5
3 7 1 11
```

<font color="blue">**Output:**</font>

```c++
3
``` 

### Explanation:

The input array is [3,0,1,8,2,4,7,6]. The windows are [3,0,1,8,2], [0,1,8,2,4], [1,8,2,4,7] and [8,2,4,7,6], and their
minimums are 0, 0, 1 and 2. Thus, the answer is $0 \oplus 0 \oplus 1 \oplus 2 = 3$.
