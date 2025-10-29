# Distinct Values Splits

You are given an array of $n$ integers. Your task is to count the number of ways to split the array into **continuous
segments** such that **each segment contains only distinct values** (i.e., no duplicates within any segment).

## Input

The first line contains an integer $n$: the size of the array.  
The second line contains $n$ integers $x_1, x_2, \dots, x_n$: the contents of the array.

## Output

Print one integer: the number of valid ways to split the array, modulo $10^9 + 7$.

## Constraints

- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$

## Example

**Input:**

```
4
1 2 1 3
```

**Output:**  
`6`

**Explanation:**  
There are six valid splits:

- `[1], [2], [1], [3]`
- `[1], [2], [1, 3]`
- `[1], [2, 1], [3]`
- `[1], [2, 1, 3]`
- `[1, 2], [1], [3]`
- `[1, 2], [1, 3]`

Note: Splits like `[1, 2, 1], [3]` are **invalid**, because the segment `[1, 2, 1]` contains a duplicate `1`.