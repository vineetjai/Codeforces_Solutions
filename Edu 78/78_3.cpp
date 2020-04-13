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
    tc{
        int n;
        cin>>n;
        if(n==0) {cout<<0<<endl; continue;}
        n=2*n;
        int a[n];
        rep(i,0,n) cin>>a[i];
        // vector<std::vector<int> >dp(n,std::vector<int>(3,0)),dp1(n,std::vector<int>(3,0));
        // dp[0][a[0]]=1;
        // rep(i,1,n){
        //     dp[i][a[i]]=dp[i-1][a[i]]+1;
        //     dp[i][3-a[i]]=dp[i-1][3-a[i]];
        // }
        // dp1[n-1][a[n-1]]=1;
        // rrep(i,n-2,0){
        //     dp[i][a[i]]=dp[i+1][a[i]]+1;
        //     dp[i][3-a[i]]=dp[i+1][3-a[i]];
        // }
        vector<int> v(n,0);
        if(a[0]==1) v[0]=1;
        else v[0]=-1;
        rep(i,1,n){
            if(a[i]==1) v[i]=v[i-1]+1;
            else v[i]=v[i-1]-1;
        }

        vector<int> v1(n,0);
        if(a[n-1]==1) v1[n-1]=1;
        else v1[n-1]=-1;
        rrep(i,n-2,0){
            if(a[i]==1) v1[i]=v1[i+1]+1;
            else v1[i]=v1[i+1]-1;
        }
        map<int,int> mp;
        rrep(i,n-1,n/2){
            mp[v1[i]]=i;
        }
        // rep(i,0,n/2){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        // rep(i,n/2,n){
        //     cout<<v1[i]<<" ";
        // }
        // cout<<endl;
        int ans=n;
        rep(i,0,n/2){
            if(v[i]==0) {
                ans=min(ans,n-i-1);
            }
            if(mp.find(-v[i])!=mp.end()){
                ans=min(ans,mp[-v[i]]-1-i);
            }
        }
        rrep(i,n-1,n/2){
            if(v1[i]==0) ans=min(ans,i);
        }
        cout<<ans<<endl;
    }
}