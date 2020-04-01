#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
int vis[64];
int gao(int x) {
    if (x == 1)
        return 0;
    return 1 + gao(x / 2);
}
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n, sum = 0;
        int m, x;
        memset(vis, 0, sizeof(vis));
        scanf("%lld%d", &n, &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d", &x);
            sum += x;
            vis[gao(x)]++;
        }
        if (sum < n) {
            puts("-1");
            continue;
        }
        int cat = 0;
        for (int i = 0; (1ll << i) <= n; i++) {
            if (n >> i & 1) {
                if (vis[i])
                    vis[i]--;
                else {
                    ++cat;
                    for (int j = 1; ;j++, cat++) {
                        if (vis[j + i]) {
                            vis[j + i]--;
                            break;
                        }
                        else 
                            vis[j + i]++;
                    }
                }
            }
            vis[i + 1] += vis[i] / 2;
        }
        printf("%d\n", cat);
    }
}