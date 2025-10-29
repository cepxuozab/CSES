# Two Array Average

You are given two arrays of $n$ integers. Your task is to select a non‑empty prefix from both arrays such that the
average of all selected numbers is as large as possible.

### Input

The first line has an integer $n$.  
The second line has $n$ integers $a_1, a_2, \dots, a_n$: the numbers in the first array.  
The third line has $n$ integers $b_1, b_2, \dots, b_n$: the numbers in the second array.

### Output

Print two numbers: the prefix sizes.  
Your answer is considered correct if the absolute or relative difference to the maximum average is at most $10^{-6}$.

### Constraints

* $1 \le n \le 10^5$
* $1 \le a_i, b_i \le 10^9$

### Example

**Input:**

```
4
1 5 5 2
3 1 3 1
```

Output:

```
3 1
```

**Explanation:** If you choose the prefixes $[1, 5, 5]$ and $[3]$, the average is $\frac{1 + 5 + 5 + 3}{4} = 3.5$, which
is the maximum possible average.

