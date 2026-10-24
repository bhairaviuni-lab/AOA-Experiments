#include <stdio.h>
#include <stdlib.h>

int x[20], n;

void nQueen(int k) {
    if (k > n) {
        for (int j = 1; j <= n; j++) printf("%d ", x[j]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        int ok = 1;
        for (int j = 1; j < k && ok; j++)
            if (x[j] == i || abs(x[j] - i) == abs(j - k)) ok = 0;
        if (ok) { x[k] = i; nQueen(k + 1); }
    }
}

int main() {
    if (scanf("%d", &n) != 1 || n < 1 || n >= 20) return 1;
    nQueen(1);
    return 0;
}