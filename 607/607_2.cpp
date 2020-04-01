#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    for (int tt = 0; tt < t; tt++) {
        string s, c;
        cin >> s >> c;
        if (s < c) {
            cout << s << "\n";
            continue;
        }
        string t = s;
        sort(t.begin(), t.end());
        int a = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] > t[i]) {
                for (int j = i + 1; j < (int) s.size(); j++) {
                    swap(s[i], s[j]);
                    if (s < c) {
                        cout << s << "\n";
                        a = 1;
                        i = s.size();
                        break;
                    }
                    swap(s[i], s[j]);
                }
            }
        }
        if (a == 0) {
            cout << "---\n";
        }
    }
    return 0;
}