#include <bits/stdc++.h>
using namespace std;
 
const int N = (1 << 18) + 5;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            for (int j = 0; j <= i; j++) {
                a[j] = 0;
            }
        }
    }
    long long ans = 0;
    for (; n >= 1; n /= 2) {
        int mi = 1E9 + 7;
        ans += a.back(); a.pop_back();
        for (int i = 0; i < n / 2; i++) {
            mi = min(mi, a.back());
            a.pop_back();
        }
        a.push_back(mi);
    }
    cout << ans;
}
