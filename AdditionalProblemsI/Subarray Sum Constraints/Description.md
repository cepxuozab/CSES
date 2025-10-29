# Subarray Sum Constraints

Your task is to construct an array $x_1, x_2, \dots, x_n$ consisting of $n$ integers. The array must satisfy $m$
constraints of the form $(l, r, s)$: the sum $x_l + x_{l+1} + \dots + x_r$ must equal $s$.

### Input

The first line has two integers $n$ and $m$: the length of the array and the number of constraints.  
The next $m$ lines each have three integers $l$, $r$ and $s$: the description of the constraints.

### Output

If a solution exists, print `YES` on the first line.  
On the second line, print $n$ integers $x_1, x_2, \dots, x_n$: the contents of the array. All elements of the array must
satisfy $-10^{15} \le x_i \le 10^{15}$ and the array must satisfy all given constraints. You can print any valid
solution.  
If no solution exists, just print `NO`.

### Constraints

* $1 \le n \le 5000$
* $0 \le m \le 2 \cdot 10^5$
* $1 \le l \le r \le n$
* $-10^9 \le s \le 10^9$

### Example

**Input:**

```
5 3
1 3 3
3 5 3
4 4 -1
```

Output:

```
YES
0 2 1 -1 3
```
