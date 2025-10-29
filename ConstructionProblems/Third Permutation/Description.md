# Third Permutation

You are given two permutations a and b such that $a_i \neq b_i$ in every position. Create a third permutation c such
that $a_i \neq c_i$ and $b_i \neq c_i$ in every position.

### Input

The first line has an integer n: the permutation size.
The second line has n integers $a_1,a_2,\dots,a_n$.
The third line has n integers $b_1,b_2,\dots,b_n$.

### Output

Print n integers $c_1,c_2,\dots,c_n$. You can print any valid solution. If there are no solutions, print IMPOSSIBLE.

### Constraints

* $1 \le n \le 2 \cdot 10^5$

### Example

**Input:**

```
5
1 3 2 5 4
4 1 3 2 5
```

Output:

```
3 2 5 4 1
```


