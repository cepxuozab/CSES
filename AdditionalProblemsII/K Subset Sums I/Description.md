# K Subset Sums I

You are given an array of $n$ integers. Consider the sums of all $2^n$ subsets of the given array (including the empty
subset with sum equal to zero).

Your task is to find the $k$ smallest subset sums.

### Input

The first line has two integers $n$ and $k$: the size of the array and the number of subset sums $k$.

The next line has $n$ integers $x_1, x_2,\dots, x_n$: the contents of the array.

### Output

Print $k$ integers: the $k$ smallest subset sums in increasing order.

### Constraints

* $1 \le n \le 2 \cdot 10^5$
* $1 \le k \le \min(2^n, 2 \cdot 10^5)$
* $-10^9 \le x_i \le 10^9$

### Example

**Input:**

```
4 9
1 6 3 -3
```

Output:

```
-3 -2 0 0 1 1 3 3 4
```



