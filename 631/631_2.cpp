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
vector<int> vis(101,0);
vector<vector<int>> adj(101);
void clr(int n){
	vis.clear();
	vis.assign(n+1,0);
	rep(i,0,101) adj[i].clear();
}
void dfs(int v,int p,set<int> &s){
	vis[v]=true;
	s.insert(v);
	fori(adj[v]){
		if(i!=p ){
			// cout<<i<<" "<<v<<endl;
			if(!vis[i]) dfs(i,v,s);
		}
	}
}
int main(){
    optimizeIO();
    tc{

    	int n,y,x;
        set<pair<int,int>> ans;
        int bflag=0;
        map<int,int> m3,m4;

        cin>>n;
        vector<int> a(n);
        rep(i,0,n) cin>>a[i];
        
        x=*max_element(a.begin(),a.end());
        rep(i,0,x) m3[a[i]]++;
        rep(i,x,n) m4[a[i]]++;
        y=*max_element(a.begin()+x,a.end());
        if(m4.size()==y && m3.size()==x && y+x==n ) ans.insert({x,y});
        
        m3.clear(),m4.clear();

        rep(i,n-x,n) m3[a[i]]++;
        rep(i,0,n-x) m4[a[i]]++;
        y=*max_element(a.begin(),a.begin()+n-x);
        if(m3.size()==x && m4.size()==y && x+y==n )ans.insert({y,x});

        if(ans.size()==0) cout<<0<<endl;
        else{
            cout<<ans.size()<<endl;
            for (auto i:ans) cout<<i.f<<" "<<i.s<<endl;
        }
    }
}