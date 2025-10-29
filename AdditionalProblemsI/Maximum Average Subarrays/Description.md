# Maximum Average Subarrays

You are given an array of $n$ integers. For each $i = 1, 2, \dots, n$, your task is to find the subarray ending at
index $i$ with the largest average. If there are multiple subarrays with the largest average, you should find the
longest one.

### Time limit

1.00 s

### Memory limit

512 MB

### Input

The first line has an integer $n$: the size of the array.  
The next line has $n$ integers $x_1, x_2, \dots, x_n$: the contents of the array.

### Output

Print $n$ integers: the length of the subarray ending at index $i$ with the largest average for
each $i = 1, 2, \dots, n$.

### Constraints

* $1 \le n \le 2 \cdot 10^5$
* $1 \le x_i \le 10^6$

### Example

**Input:**

```
7
1 6 4 6 2 5 5
```

Output:

```
1 1 2 1 4 1 2
```

### Explanation

Consider $i = 5$ (the fifth element, which is `2` in the array). We examine all subarrays ending at index 5:

1. $[1, 6, 4, 6, 2]$ → average = $\frac{1 + 6 + 4 + 6 + 2}{5} = \frac{19}{5} = 3.8$
2. $[6, 4, 6, 2]$ → average = $\frac{6 + 4 + 6 + 2}{4} = \frac{18}{4} = 4.5$
3. $[4, 6, 2]$ → average = $\frac{4 + 6 + 2}{3} = \frac{12}{3} = 4$
4. $[6, 2]$ → average = $\frac{6 + 2}{2} = \frac{8}{2} = 4$
5. $[2]$ → average = $\frac{2}{1} = 2$

The largest average is 4.5, and the corresponding subarray $[6, 4, 6, 2]$ has length 4. Thus, for $i = 5$, the answer is
`4`.

**Step-by-step breakdown of the full output:**

- $i = 1$: only subarray $[1]$ → avg = 1 → length = 1
- $i = 2$:
    - $[1,6]$ → avg = 3.5
    - $[6]$ → avg = 6 → best (length = 1)
- $i = 3$:
    - $[1,6,4]$ → avg ≈ 3.67
    - $[6,4]$ → avg = 5
    - $[4]$ → avg = 4 → best is $[6,4]$ (length = 2)
- $i = 4$:
    - Best is $[6]$ (last element) → avg = 6 → length = 1
- $i = 5$: as above → length = 4
- $i = 6$:
    - Best is $[5]$ → avg = 5 → length = 1
- $i = 7$:
    - $[5,5]$ → avg = 5
    - $[5]$ → avg = 5 → tie; pick longer → length = 2

Thus, the final output is: `1 1 2 1 4 1 2`.
