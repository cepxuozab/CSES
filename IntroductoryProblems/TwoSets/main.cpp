#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    if (N % 4 == 1 || N % 4 == 2) printf("NO\n");
    else {
        printf("YES\n");
        printf("%d\n", N / 2);
        int diff = N % 4 == 0 ? 1 : 0;
        for (int i = 2; i <= N / 2; i += 2)
            printf("%d %d ", i, N - i + diff);
        diff == 0 ? printf("%d\n%d\n", N, N / 2 + 1) : printf("\n%d\n", N / 2);
        for (int i = 1; i <= N / 2; i += 2)
            printf("%d %d ", i, N - i + diff);
    }
}