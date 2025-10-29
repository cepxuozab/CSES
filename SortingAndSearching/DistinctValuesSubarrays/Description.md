# Distinct Values Subarrays

Given an array of n integers, count the number of subarrays where each element is dictinct.

### Input

The first line has an integer n: the array size.
The second line has n integers $x_1,x_2,\dots,x_n$: the array contents.

### Output

Print the number of subarrays with distinct elements.

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
8
```

_Explanation:_ The subarrays are `[1]` (two times), `[2], [3], [1,2], [1,3], [2,1] and [2,1,3]`.
