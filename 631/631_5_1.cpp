#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while(t--)
    {
        int h, g, n, m, a;
        long long sum = 0;
        cin >> h >> g;
        n = pow(2, h) - 1;
        m = pow(2, g) - 1;
        vector<pair<int, int> >nodes;
        for(int j = 1; j <= n; j++)
        {
            cin >> a;
            nodes.push_back({a, j});
        }
        sort(nodes.begin(), nodes.end());
        vector<int>tree(n + 1, 0);
        vector<int>used(n + 1, 0);
        for(int j = 0; j < n; j++)
        {
            int i = nodes[j].second;
            while(i > m || tree[i])
            {
                i /= 2;
            }
            if(i == 0)continue;
            if(tree[2 * i] == tree[2 * i + 1])
            {
                tree[i] = 1;
                sum += nodes[j].first;
                used[nodes[j].second] = 1;
            }
        }
        cout << sum << endl;
        for(int j = n; j >= 1; j--)if(!used[j])cout << j << " ";
        cout << endl;
    }
    return 0;
}
