# All Subarray Xors

Given an array of n integers, your task is to find all integers that are the xor sum in some subarray.

### Input

The first line has an integer n: the size of the array.
The next line has n integers $x_1,x_2,\dots,x_n$: the contents of the array.

### Output

First print an integer k: the number of distinct integers that are the xor sum in some subarray.
After this print k integers: the xor sums in increasing order.

### Constraints

* $1 \le n \le 2 \cdot 10^5$
* $0 \le x_i \le 10^6$

### Example

**Input:**

```
4
5 1 5 9
```

Output:

```
7
1 4 5 8 9 12 13ы
```


