# Same Sum Subsets

Given a set of $n$ positive integers, your task is to choose two disjoint subsets of the elements that have the same
sum.

### Input

The first line has an integer $n$: the set size.

The second line has $n$ integers $x_1,x_2,\dots,x_n$: the set elements.

### Output

For both subsets, first print the size of the subset and then its contents. You can print any valid solution. If there
is no solution, print `IMPOSSIBLE`.

### Constraints

* $3 \le n \le 40$
* $\sum_{i=1}^{n} x_i \le 2^{n}-2$

### Example

**Input:**

```
6
1 2 3 5 7 8
```

Output:

```
2
2 3
1
5
```

**Explanation:** The first subset is $\{2,3\}$ and the second subset is $\{5\}$.