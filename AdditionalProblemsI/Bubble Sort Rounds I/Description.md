# Bubble Sort Rounds I

Bubble sort is a sorting algorithm that consists of a number of rounds. On each round the algorithm scans the array from
left to right and swaps any adjacent elements that are in the wrong order.

Given an array of $n$ integers, calculate the number of bubble sort rounds needed to sort the array.

### Input

The first line has an integer $n$: the array size.  
The next line has $n$ integers $x_1, x_2, \dots, x_n$: the array contents.

### Output

Print one integer: the number of rounds.

### Constraints

* $1 \le n \le 2 \cdot 10^5$
* $1 \le x_i \le 10^9$

### Example

**Input:**

```
5
3 2 4 1 4
```

Output:

```
3
```

**Explanation:** Bubble sort needs three rounds to sort this array. The array contents after each round are
`[2,3,1,4,4]`, `[2,1,3,4,4]`, and `[1,2,3,4,4]`.