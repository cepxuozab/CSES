# Permutation Order

Let p(n,k) denote the kth permutation (in lexicographical order) of $1 \dots n$. For example, `p(4,1)=[1,2,3,4]` and
`p(4,2)=[1,2,4,3]`.
Your task is to process two types of tests:

* Given n and k, find p(n,k)
* Given n and p(n,k), find k

### Input

The first line has an integer t: the number of tests.
Each test is either "1 n k" or "2 n p(n,k)".

### Output

For each test, print the answer according to the example.

### Constraints

* $1 \le t \le 1000$
* $1 \le n \le 20$
* $1 \le k \le n!$

### Example

**Input:**

```
6
1 4 1
1 4 2
2 4 1 2 3 4
2 4 1 2 4 3
1 5 42
2 5 2 4 5 3 1
```

**Output:**

```
1 2 3 4
1 2 4 3
1
2
2 4 5 3 1
42
```

