#include <iostream>
#include <vector>
#include <queue> //priority queue
#include <stack>
#include <map> // multimap
#include <set> //multiset
#include <list>
#include <utility> // pair
#include <iterator>
#include <deque> // insertion as both ends
#include <string>
// g1=s.substr(0,n/2);
// g2=s.substr(n/2+n%2,n/2);
#include <cctype> //isaplha
#include <iomanip>      // std::setprecision
#include <algorithm> //binary_search,sort, next_permutation in lexicographically greater permutation, fill(it1,it2,val)
#include <cmath>
#include <limits.h> //INT_MIN,INT_MAX
#include <numeric>  //iota,partial_sum,inner_product,accumulate(begin,end,num)
#include <functional>  //Arithmetic, comparators, logical
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
// #include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define tc int t; cin >> t; while(t--)

using namespace std;
string repeat(string s, int n) {
    string s1 = s;
    for (int i=1; i<n;i++)
        s += s1;
    return s;
}
string getString(char x) {
    string s(1, x);
    return s;
}

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if (a == 0)  return b;
    return gcd(b % a, a);
}

int main(){
    optimizeIO();
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cntR=0,cnt=0;
    for(int i=0;i<n;i++){
      if(s[i]=='L') cnt+=cntR;
      else cntR++;
    }
    if(cnt<k){
      cout<<-1<<endl;return 0;
    }
    vector<int> ps;
    for(int i=0;i<n-1;i++) if(s[i]=='R' && s[i+1]=='L') ps.pb(i);
    int p=0;
    vector<vector<int>> ans(k);
    for(int i=0;i<k;i++){
        int t = min(int(ps.size()) - p, cnt - (k-1 - i));
        for (int j = 0; j < t; ++j, ++p) {
            swap(s[ps[p]], s[ps[p] + 1]);
            ans[i].push_back(ps[p]);
            if (ps[p] > 0 && s[ps[p] - 1] == 'R')
                ps.push_back(ps[p] - 1);
            if (ps[p] + 1 < n - 1 && s[ps[p] + 2] == 'L')
                ps.push_back(ps[p] + 1);
        }
        cnt -= t;
    }
    if (cnt > 0) {
        cout << -1 << "\n";
        return 0;
    }
    for (auto v : ans) {
        cout << v.size();
        for (auto a : v)
            cout << " " << a + 1;
        cout << "\n";
    }
    return 0;
}
