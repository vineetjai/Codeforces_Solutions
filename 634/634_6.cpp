#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define x first
#define y second
int main()
{
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;

    vector<vector<int> >v(n, vector<int>(m, 0));
    vector<pii>cells[2];
    for (int i = 0; i < n; i++) {
      string s; cin >> s;
      for (int j = 0; j < m; j++) {
        v[i][j] = (s[j] - '0');
        cells[v[i][j]].push_back({i, j});
      }
    }

    vector<string>dir;
    for (int i = 0; i < n; i++) {
      string s; cin >> s;
      dir.push_back(s);
    }

    vector<vector<vector<pii> > >lft(2, vector<vector<pii> >(n, vector<pii>(m, pii(0, 0))));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x = i, y = j;
        if (dir[i][j] == 'U') x--;
        if (dir[i][j] == 'D') x++;
        if (dir[i][j] == 'L') y--;
        if (dir[i][j] == 'R') y++;

        lft[0][i][j] = {x, y};
      }
    }

    int cur = 1, pre = 0;
    for (int lv = 1; lv < 23; lv++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          pii p = lft[pre][i][j];
          lft[cur][i][j] = lft[pre][p.x][p.y];
        }
      }
      swap(cur, pre);
    }

    set<pii>se;
    int a = 0, b = 0;
    for (int c = 0; c < 2; c++) {
      for (pii p : cells[c]) {
        if (!se.count(lft[pre][p.x][p.y])) {
          se.insert(lft[pre][p.x][p.y]);
          if (c == 0) {
            ++b;
          }
          ++a;
        }
      }
    }
    cout << a << " " << b << "\n";
  }
  return 0;
}
