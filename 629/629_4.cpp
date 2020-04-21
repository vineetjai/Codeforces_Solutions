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
int solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if (count(a.begin(), a.end(), a[0]) == n) {
		cout << 1 << endl;
		for (int i = 0; i < n; ++i) {
			cout << 1 << " ";
		}
		cout << endl;
		return 0;
	}

	if (n % 2 == 0) {
		cout << 2 << endl;
		for (int i = 0; i < n; ++i) {
			cout << i % 2 + 1 << " ";
		}
		cout << endl;
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] == a[(i + 1) % n]) {
			vector<int> ans(n);
			for (int j = 0, pos = i + 1; pos < n; ++pos, j ^= 1) {
				ans[pos] = j + 1;
			}
			for (int j = 0, pos = i; pos >= 0; --pos, j ^= 1) {
				ans[pos] = j + 1;
			}
			cout << 2 << endl;
			for (int pos = 0; pos < n; ++pos) {
				cout << ans[pos] << " ";
			}
			cout << endl;
			return 0;
		}
	}

	cout << 3 << endl;
	for (int i = 0; i < n - 1; ++i) {
		cout << i % 2 + 1 << " ";
	}
	cout << 3 << endl;
    return 0;
}

int main(){
    optimizeIO();
    tc{
      // int n;
      // cin>>n;
      // int a[n];
      // rep(i,0,n) cin>>a[i];
      //
      // int ans1[n];
      // rep(i,0,n){
      //   set<int> s1;
      //   rep(j,0,3) s1.insert(j+1);
      //   if(i==0 ){
      //     ans1[0]=1;
      //   }
      //   else if(i==n-1){
      //     if(a[i-1]!=a[i]) s1.erase(ans1[i-1]);
      //     if(a[i]!=a[0]) s1.erase(ans1[0]);
      //     ans1[i]=*s1.begin();
      //   }
      //   else{
      //     if(a[i-1]!=a[i]) {
      //       s1.erase(ans1[i-1]);
      //       ans1[i]=*s1.begin();
      //     }
      //     else ans1[i]=ans1[i-1];
      //   }
      // }
      // set<int> s(ans1,ans1+n);
      // cout<<s.size()<<endl;
      // rep(i,0,n) cout<<ans1[i]<<" ";
      // cout<<endl;
      solve();
    }
}
