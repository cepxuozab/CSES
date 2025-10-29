# Raab Game II

Consider a two player game where each player has n cards numbered 1,2,\dots,n. On each turn both players place one of
their cards on the table. The player who placed the higher card gets one point. If the cards are equal, neither player
gets a point. The game continues until all cards have been played.
You are given the number of cards n and the players' scores at the end of the game, a and b. Your task is to count the
number of possible games with that outcome.

### Input

The first line contains one integer t: the number of tests.
Then there are t lines, each with three integers n, a and b.

### Output

For each test case print the number of possible games modulo $10^9+7$.

### Constraints

* $1 \le n \le 5000$
* $1 \le t \le 1000$
* $0 \le a,b \le n$

### Example

**Input:**

```
5
3 1 2
2 0 1
5 2 2
9 3 5
4 4 1
```

Output:

```
6
0
4200
976757050
0
```
