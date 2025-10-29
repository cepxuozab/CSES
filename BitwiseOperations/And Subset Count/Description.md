# And Subset Count

You are given an array of n integers. Your task is to calculate the number of non-empty subsets whose elements' bitwise
and is equal to k for each $k = 0, 1,\dots, n$.

### Input

The first line has an integer n: the size of the array.
The next line has n integers $a_1, a_2,\dots, a_n$: the contents of the array.

### Output

Print n + 1 integers as specified above modulo $10^9 + 7$.

### Constraints

* $1 \le n \le 2 \cdot 10^5$
* $0 \le a_i \le n$

### Example

**Input:**

```
4
3 1 3 4
```

Output:

```
7 4 0 3 1
```


