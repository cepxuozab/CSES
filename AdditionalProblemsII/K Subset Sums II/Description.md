# K Subset Sums II

You are given an array of $n$ integers. Consider the sums of all $\binom{n}{m}$ subsets of the given array with
exactly $m$ elements.

Your task is to find the $k$ smallest subset sums.

### Input

The first line has three integers $n$, $m$ and $k$: the size of the array, the size of the subsets and the number of
subset sums $k$.

The next line has $n$ integers $x_1, x_2,\dots, x_n$: the contents of the array.

### Output

Print $k$ integers: the $k$ smallest subset sums in increasing order.

### Constraints

* $1 \le m < n \le 2 \cdot 10^5$
* $1 \le k \le \min\left(\binom{n}{m}, 2 \cdot 10^5\right)$
* $-10^9 \le x_i \le 10^9$

### Example

**Input:**

```
5 3 9
-3 1 5 2 0
```

Output:

```
-2 -1 0 2 3 3 4 6 7
```



