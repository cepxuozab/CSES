# Distinct Values Sum

You are given an array $x_1, x_2, \dots, x_n$. Let $d(a,b)$ denote the number of distinct values in the
subarray $x_a, x_{a+1}, \dots, x_b$.

Your task is to calculate the sum  
$$
\sum_{a=1}^n \sum_{b=a}^n d(a,b),
$$  
i.e., the sum of $d(a,b)$ over all subarrays.

## Input

The first line contains an integer $n$: the size of the array.  
The second line contains $n$ integers $x_1, x_2, \dots, x_n$: the elements of the array.

## Output

Print one integer: the required sum.

## Constraints

- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$

## Example

**Input:**

```
5
1 2 3 1 1
```

**Output:**  
`29`

**Explanation:**  
In this array:

- 6 subarrays have 1 distinct value,
- 4 subarrays have 2 distinct values,
- 5 subarrays have 3 distinct values.

Thus, the total sum is  
$$
6 \cdot 1 + 4 \cdot 2 + 5 \cdot 3 = 29.
$$