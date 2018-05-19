#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

const int C = 200 + 5;

int b[C], l[C], r[C];
char a[C][C];

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        int c;
        scanf("%d", &c);
        for (int i = 1; i <= c; i++) {
            scanf("%d", &b[i]);
        }
        if (b[1] == 0 || b[c] == 0) {
            printf("Case #%d: IMPOSSIBLE\n", kase);
            continue;
        }
        int rows = 0;
        for (int i = 1; i <= c; i++) {
            l[i] = r[i - 1] + 1;
            r[i] = l[i] + b[i] - 1;
            rows = max(rows, max(abs(l[i] - i), abs(r[i] - i)) + 1);
            cerr<<l[i]<<" "<<r[i]<<endl;
        }
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= c; j++) {
                a[i][j] = '.';
            }
        }
        for (int i = 1; i <= c; i++) {
            if (b[i] == 0) {
                continue;
            }
            for (int j = l[i]; j < i; j++) {
                for (int k = 1; k <= i - j; k++) {
                    a[k][j + k - 1] = '\\';
                }
            }
            for (int j = i + 1; j <= r[i]; j++) {
                for (int k = 1; k <= j - i; k++) {
                    a[k][j - k + 1] = '/';
                }
            }
        }
        printf("Case #%d: %d\n", kase, rows);
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= c; j++) {
                putchar(a[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}
