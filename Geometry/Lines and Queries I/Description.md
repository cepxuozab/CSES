# Lines and Queries I

Your task is to efficiently process the following types of queries:

* Add a line ax+b
* Find the maximum point in any line at position x

### Input

The first line has an integer n: the number of queries.
The following n lines describe the queries. The format of each line is either "1 a b" or "2 x".
You may assume that the first query is of type 1.

### Output

Print the answer for each query of type 2.

### Constraints

* $1 \le n \le 2 \cdot 10^5$
* $-10^9 \le a,b \le 10^9$
* $0 \le x \le 10^5$

### Example

**Input:**

```
6
1 1 2
2 1
2 3
1 0 4
2 1
2 3
```

**Output:**

```
3
5
4
5
```

