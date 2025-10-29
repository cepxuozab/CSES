# Subsets with Fixed Average

You are given an array of $n$ integers. Your task is to count the number of non‑empty subsets of the given array with
average equal to $a$.

### Input

The first line has two integers $n$ and $a$: the size of the array and the target average.  
The next line has $n$ integers $x_1, x_2, \dots, x_n$: the contents of the array.

### Output

Print one integer: the number of non‑empty subsets with average equal to $a$, modulo $10^9 + 7$.

### Constraints

* $1 \le n \le 500$
* $1 \le a \le 500$
* $1 \le x_i \le 500$

### Example

**Input:**

```
5 2
1 1 2 3 4
```

Output:

```
7
```

