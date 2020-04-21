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

// int main(){
//     optimizeIO();
//     tc{
// 			int n;
// 			cin>>n;
// 			int a[n];
// 			rep(i,0,n) cin>>a[i];
//
// 			int ans=0;
// 			map<int,int> m1;
// 			rep(i,0,n) m1[a[i]]++;
// 			for(auto i:m1) ans=max(ans,i.second);
// 			vector<pair<int,bool>> v;
// 			vector<int> x[201];
// 			for(int i=0;i<n;i++) x[a[i]].pb(i);
//
// 			vector<vector<int>> dp(n,vector<int>(201,0));
// 			dp[0][a[0]]=1;
// 			for(int j=1;j<n;j++){
// 				dp[j]=dp[j-1];
// 				dp[j][a[j]]++;
// 			}
//
// 			vector<vector<int>> rev_dp(n,vector<int>(201,0));
// 			rev_dp[n-1][a[n-1]]=1;
// 			for(int j=n-2;j>=0;j--){
// 				rev_dp[j]=rev_dp[j+1];
// 				rev_dp[j][a[j]]++;
// 			}
//
// 			for(auto i:m1){
// 				int num=i.first;
// 				for(int j=0;j<x[num].size();j++)
// 					for(int k=j;k<x[num].size();k++)
// 						for(int l=1;l<=200;l++)
// 							if(l!=num )
// 								ans=max(ans,dp[x[num][k]][num]-dp[x[num][j]][num]+1+min(rev_dp[x[num][k]][l],dp[x[num][j]][l])*2);
// 			}
// 			cout<<ans<<endl;
//
//     }
// }

int arr[200005];
int prefix[200005][200];
vector<int> idx[205];
int n;
int getFreq(int st,int endd,int element)
{
    return prefix[endd][element] - prefix[st-1][element];
}
int getBest(int st,int endd,int ele)
{
    int ans = 0;
    for(int i = 0;i < 200;i++)
    {
        if(i != ele)
        {
            //int minf = min(getFreq(st,endd,i));
            ans = max(ans,getFreq(st,endd,i));
        }
    }
    return ans;
}
int getAns(int st,int en,int ele)
{
    int freq = getFreq(st,en,ele);
    return freq + getBest(st,en,ele);
}
int32_t main()
{
    optimizeIO();
    //freopen("robots.in","r",stdin);
    int _ = 1;
    cin >> _;
    int curTest = 1;
    while(_--)
    {
        cin >> n;
        for(int i = 0;i <= n+1;i++)
            for(int j = 0;j < 200;j++)
                prefix[i][j] = 0;
        for(int i = 0;i < 200;i++)
            idx[i].clear();
        for(int i = 1;i <= n;i++)
        {
            cin >> arr[i];
            arr[i]--;
            idx[arr[i]].push_back(i);
            prefix[i][arr[i]]++;
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j < 200;j++)
                prefix[i][j] += prefix[i-1][j];
        }
        int ans = 0;
        for(int j = 0;j < 200;j++)
        {
            ans = max(ans,(int)idx[j].size());
            for(int i = 0;i < idx[j].size()/2;i++)
            {
                int curStart = idx[j][i];
                int curEnd = idx[j][idx[j].size() - i - 1];
                ans = max(ans,(i+1)*2 + getBest(curStart + 1,curEnd - 1,j));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
