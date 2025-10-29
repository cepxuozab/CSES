# Range Interval Queries

Given an array x of n integers, your task is to process q queries of the form: how many integers i
satisfy $a \le i \le b$ and $c \le x_i \le d$?

### Input

The first line has two integers n and q: the number of values and queries.
The second line has n integers $x_1,x_2,\dots,x_n$: the array values.
Finally, there are q lines describing the queries. Each line has four integers a, b, c and d: how many integers i
satisfy $a \le i \le b$ and $c \le x_i \le d$?

### Output

Print the result of each query.

### Constraints

* $1 \le n,q \le 2 \cdot 10^5$
* $1 \le x_i \le 10^9$
* $1 \le a \le b \le n$
* $1 \le c \le d \le 10^9$

### Example

**Input:**

```
8 4
3 2 4 5 1 1 5 3
2 4 2 4
5 6 2 9
1 8 1 5
3 3 4 4
```

**Output:**

```
2
0
8
1
```

