# Minimum Cost Pairs

Given an array of $n$ integers, consider pairings of $k$ pairs. Each number can appear in at most one pair, and the cost
of a pair $(a,b)$ is $|a-b|$. The cost of a pairing is the sum of all costs of the pairs.

Calculate the minimum costs of pairings for $k=1,2,\dots,\lfloor n/2 \rfloor$.

### Input

The first line has an integer $n$: the array size.

The next line has $n$ integers $x_1,x_2,\dots,x_n$: the array contents.

### Output

Print $\lfloor n/2 \rfloor$ integers: the minimum costs of pairings.

### Constraints

* $2 \le n \le 2 \cdot 10^5$
* $1 \le x_i \le 10^9$

### Example

**Input:**

```
8
3 1 2 7 9 3 4 7
```

Output:

```
0 0 1 6
```

**Explanation:** Possible minimum-cost pairings are $[(3,3)]$, $[(3,3),(7,7)]$, $[(1,2),(3,3),(7,7)]$
and $[(1,2),(3,3),(4,7),(7,9)]$.