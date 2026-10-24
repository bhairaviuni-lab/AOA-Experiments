#include <stdio.h>
#include <string.h>

int main() {
    char t[100], p[50];
    scanf("%s %s", t, p);
    
    int n = strlen(t), m = strlen(p), f = 0;

    for (int i = 0; i <= n - m; i++)
        if (!strncmp(t + i, p, m))
            printf("Pattern found at shift %d\n", i), f = 1;

    if (!f) printf("Pattern not found");
    return 0;
}