# Graph Coloring

You are given a simple graph with n nodes and m edges. Your task is to use the minimum possible number of colors to
color each node such that no edge connects two nodes of the same color.

### Input

The first line has two integers n and m: the number of nodes and edges. The nodes are numbered $1, 2,\dots, n$.
Then there are m lines describing the edges. Each line has two integers a and b: there is an edge connecting nodes a and
b.

### Output

First, print an integer k: the minimum number of colors.
After this, print n integers $c_1, c_2,\dots, c_n$: the colors of the nodes. The colors should
satisfy $1 \le c_i \le k$.
You may print any valid solution.

### Constraints

* $1 \le n \le 16$
* $0 \le m \le \frac{n(n-1)}{2}$

### Example

**Input:**

```
4 4
1 2
2 3
3 4
4 1
```

Output:

```
2
1 2 1 2
```




