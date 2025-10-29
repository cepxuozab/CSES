# Distinct Values Queries II

Given an array of n integers, your task is to process q queries of the following types:

* update the value at position k to u
* check if every value in range `[a, b]` is distinct

### Input

The first line has two integers n and q: the number of values and queries.
The second line has n integers $x_1, x_2,\dots, x_n$: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".

### Output

For each query of type 2, print YES if every value in the range is distinct and NO otherwise.

### Constraints

* $1 \le n, q \le 2 \cdot 10^5$
* $1 \le x_i, u \le 10^9$
* $1 \le k \le n$
* $1 \le a \le b \le n$

### Example

**Input:**

```
5 4
3 2 7 2 8
2 3 5
2 2 5
1 2 9
2 2 5
```

**Output:**

```
YES
NO
YES
```

