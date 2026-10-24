#include <stdio.h>

void quickSort(int a[], int l, int h) {
    if (l >= h) return;
    int p = a[h], i = l;
    for (int j = l; j < h; j++)
        if (a[j] < p) { int t = a[i]; a[i++] = a[j]; a[j] = t; }
    int t = a[i]; a[i] = a[h]; a[h] = t;
    
    quickSort(a, l, i - 1);
    quickSort(a, i + 1, h);
}

int main() {
    int a[] = {10, 7, 8, 9, 1, 5}, n = 6;
    quickSort(a, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}