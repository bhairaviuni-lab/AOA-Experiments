#include <stdio.h>
#include <string.h>

int main() {
    char txt[100], pat[50];
    scanf("%s %s", txt, pat);

    int n = strlen(txt), m = strlen(pat), d = 256, q = 101, p = 0, t = 0, h = 1, f = 0;

    for (int i = 0; i < m - 1; i++) h = (h * d) % q;
    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t && !strncmp(txt + i, pat, m))
            printf("Pattern found at shift %d\n", i), f = 1;

        if (i < n - m)
            t = (d * (t - txt[i] * h) + txt[i + m]) % q, t = (t < 0) ? t + q : t;
    }

    if (!f) printf("Pattern not found");
    return 0;
}