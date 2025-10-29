# Border Subgrid Count II

You are given a grid of letters. Your task is to calculate, for each letter, the number of **rectangular** subgrids
whose border consists of that letter.

### Input

The first line has two integers n and k: the size of the grid and the number of letters. The letters are the first k
uppercase letters.
After this, there are n lines that describe the grid. Each line has n letters.

### Output

Print k lines: for each letter, the number of subgrids.

### Constraints

* $1 \le n \le 500$
* $1 \le k \le 26$

### Example

**Input:**

```
5 3
ABBBC
ABABC
ABBBC
ABBBC
CCCCC
```

Output:

```
11
38
29
```
