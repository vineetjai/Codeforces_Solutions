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

int n,m;
vector<vector<int>> adj;
vector<int> depth,vis,par;
vector<int> tin,tout;
int timer;
void dfs (int v,int p){
  vis[v]=true;
  par[v]=p;
  tin[v]=timer++;
  for(auto i:adj[v]){
    if(!vis[i]){
      dfs(i,v);
      depth[v]=max(depth[v],depth[i]+1);
    }
  }
  tout[v]=timer++;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q,x,y;
    cin>>n>>q;
    adj.resize(n,vector<int>());
    rep(i,0,n-1){
      cin>>x>>y;
      adj[x-1].pb(y-1);
      adj[y-1].pb(x-1);
    }
    depth.assign(n,1);
    vis.assign(n,0);
    tin.assign(n,0);
    tout.assign(n,0);
    par.assign(n,-1);
    timer=0;
    dfs(0,-1);

    rep(i,0,q){
      int k;
      cin>>k;
      vector<int> v1;
      rep(j,0,k){
        cin>>x;
        if(par[x-1]==-1) continue;
        v1.pb(par[x-1]);
      }

      auto comp=[](const int &x,const int &y){ return tin[x]<tin[y];};
      sort(v1.begin(),v1.end(),comp);

      vector<int> v2=v1;
      auto comp1=[](const int &x, const int &y){ return tout[x]>tout[y];};
      sort(v2.begin(),v2.end(),comp1);
      
      int flag=1;
      rep(j,0,v1.size()) if(v1[j]!=v2[j]) flag=0;

      if(flag) cout<<"YES\n";
      else cout<<"NO\n";
   }
}
