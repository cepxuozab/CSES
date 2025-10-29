# System of Linear Equations

You are given $n\cdot(m+1)$ coefficients $a_{i,j}$ and $b_i$ which form the following n linear equations:

* $a_{1,1}x_1 + a_{1,2}x_2 + \dots + a_{1,m}x_m = b_1 \pmod {10^9 + 7}$
* $a_{2,1}x_1 + a_{2,2}x_2 + \dots + a_{2,m}x_m = b_2 \pmod {10^9 + 7}$
* $\dots$
* $a_{n,1}x_1 + a_{n,2}x_2 + \dots + a_{n,m}x_m = b_n \pmod {10^9 + 7}$

Your task is to find any m integers $x_1, x_2, \dots, x_m$  that satisfy the given equations.

### Input

The first line has two integers n and m: the number of equations and variables.
The next n lines each have m+1 integers $a_{i,1}, a_{i,2}, \dots, a_{i,m}, b_i$: the coefficients of the i-th equation.

### Output

Print m integers $x_1, x_2,\dots, x_m$: the values of the variables that satisfy the equations. The values must also
satisfy $0 \le x_i < 10^9 + 7$. You can print any valid solution. If no solution exists print only -1.

### Constraints

* $1 \le n, m \le 500$
* $0 \le a_{i,j}, b_i < 10^9 + 7$

### Example

**Input:**

```
3 3
2 0 1 7
1 2 0 0
1 3 1 2
```

**Output:**

```
2 1000000006 3
```

