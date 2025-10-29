# Permutation Prime Sums

Given n, create two permutations a and b of size n such that $a_i+b_i$ is prime for $i=1,2,\dots,n$.

### Input

The only line has an integer n.

### Output

Print two permutations. You can print any valid solution. If there are no solutions, print IMPOSSIBLE.

### Constraints

* $1 \le n \le 10^5$

### Example

**Input:**

```
5
```

Output:

```
2 1 3 5 4
5 1 4 2 3
```

_Explanation:_ The sums are $2+5=7, 1+1=2, 3+4=7, 5+2=7$ and $4+3=7$ which all are primes.


