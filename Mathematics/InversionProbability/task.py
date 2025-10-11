from fractions import Fraction

n = int(input())
r = [int(x) for x in input().split(" ")]

answer = Fraction(0, 1)
for a in range(n):
    for b in range(a + 1, n):
        count = 0
        for x_a in range(1, r[a] + 1):
            count += min(x_a - 1, r[b])
        answer += Fraction(count, r[a] * r[b])

answer = float(round(answer, 6))
print(f"{answer:06f}")