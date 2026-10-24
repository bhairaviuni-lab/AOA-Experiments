#include <stdio.h>

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        int t = a[min]; a[min] = a[i]; a[i] = t;
    }
}

int main() {
    int n, a[50];
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    selectionSort(a, n);

    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}