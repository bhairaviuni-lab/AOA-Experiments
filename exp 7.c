#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[50];
    int dp[51][51] = {0};

    scanf("%s %s", a, b);
    int m = strlen(a), n = strlen(b);

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (a[i-1] == b[j-1]) ? dp[i-1][j-1] + 1 
                      : (dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);

    printf("LCS length = %d", dp[m][n]);
    return 0;
}
