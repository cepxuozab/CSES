# Distinct Values Subsequences

Given an array of n integers, count the number of subsequences where each element is dictinct.
A subsequence is a sequence of array elements from left to right that may have gaps.

### Input

The first line has an integer n: the array size.
The second line has n integers $x_1,x_2,\dots,x_n$: the array contents.

### Output

Print the number of subsequences with distinct elements. The answer can be large, so print it modulo $10^9+7$.

### Constraints

* $1 \le n \le 2 \cdot 10^5$
* $1 \le x_i \le 10^9$

### Example

**Input:**

```
4
1 2 1 3
```

**Output:**

```
11
```

_Explanation:_ The subsequences are `[1]` (two times), `[2], [3], [1,2], [1,3]` (two times),
`[2,1], [2,3], [1,2,3] and [2,1,3]`.
