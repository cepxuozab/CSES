# Permuted Binary Strings

There is a hidden permutation $a_1, a_2,\dots, a_n$ of integers $1, 2,\dots, n$. Your task is to find this permutation.
To do this, you can ask questions: you can choose a binary string $b_1b_2\dots b_n$, and you will receive the binary
string $b_{a_1}b_{a_2}\dots b_{a_n}$.

### Interaction

This is an interactive problem. Your code will interact with the grader using standard input and output. You should
start by reading a single integer n: the length of the permutation.
On your turn, you can print one of the following:

* "$?\ b_1b_2\dots b_n$", where $b_i\in\{0, 1\}:$ The grader will return the binary
  string $b_{a_1}b_{a_2}\dots b_{a_n}$.
* "$!\ a_1\ a_2 \dots a_n$": report that the hidden permutation is $a_1, a_2,\dots, a_n$. Your program must terminate
  after this.

Each line should be followed by a line break. You must make sure the output gets flushed after printing each line.

### Constraints

* $1 \le n \le 1000$
* you can ask at most 10 questions of type ?

### Example

```
3
? 100
100
? 010
001
? 001
010
! 1 3 2
```

**Explanation:** The hidden permutation is `[1, 3, 2]`. In the first question $b_1b_2b_3 = 100$ and the grader
returns $b_{a_1}b_{a_2}b_{a_3} = b_1b_3b_2 = 100$. In the second question $b_1b_2b_3 = 010$ and the grader
returns $b_1b_3b_2 = 001$.
