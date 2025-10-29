# Bubble Sort Rounds II

Bubble sort is a sorting algorithm that consists of a number of rounds. On each round the algorithm scans the array from
left to right and swaps any adjacent elements that are in the wrong order.

Given an array of $n$ integers, find out the contents of the array after $k$ bubble sort rounds.

### Input

The first line has two integers $n$ and $k$: the array size and the number of rounds.  
The next line has $n$ integers $x_1, x_2, \dots, x_n$: the array contents.

### Output

Print $n$ integers: the contents of the array after $k$ rounds.

### Constraints

* $1 \le n \le 2 \cdot 10^5$
* $0 \le k \le 10^9$
* $1 \le x_i \le 10^9$

### Example

**Input:**

```
5 2
3 2 4 1 4
```

Output:

```
2 1 3 4 4
```

