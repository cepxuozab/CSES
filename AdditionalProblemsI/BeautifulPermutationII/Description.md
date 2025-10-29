# Beautiful Permutation II

## Problem Statement

A permutation of integers `1, 2, ..., n` is called **beautiful** if there are no adjacent elements whose difference is
`1`.

Given `n`, construct the **lexicographically minimal** beautiful permutation if such a permutation exists.

## Input

The only line contains an integer `n` (1 ≤ n ≤ 10^6).

## Output

Print the lexicographically minimal beautiful permutation of integers `1, 2, ..., n`. If there is no such permutation,
print `"NO SOLUTION"`.

## Examples

### Example 1

**Input:**

```
5
```

**Output:**

```
1 3 5 2 4
```

### Example 2

**Input:**

```
3
```

**Output:**

```
NO SOLUTION
```

### Example 3

**Input:**

```
4
```

**Output:**

```
2 4 1 3
```