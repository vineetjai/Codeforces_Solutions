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

int main(){
    optimizeIO();
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n) cin>>a[i];
    int mx=1,flag=0;
    vector<int> b(n,1);
    b[n-1]=1;
    rep(i,1,n){
        if(a[i]>a[i-1]) b[i]+=b[i-1];
    }
    vector<int> c(n,1);
    c[n-1]=1;
    rrep(i,n-2,0){
        if(a[i]<a[i+1]) c[i]+=c[i+1];
    }
    int ans=1;
    rep(i,1,n-1){
        if(a[i+1]>a[i-1]) ans=max(ans,b[i-1]+c[i+1]);
        ans=max(ans,b[i]);
        ans=max(ans,c[i]);
    }
    ans=max(ans,c[0]);
    ans=max(ans,b[n-1]);
    cout<<ans<<endl;
}