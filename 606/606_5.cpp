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
set<int> s1;
set<int> s2;
int a,b;
vector<bool> visited(200005,0);
void dfs(int vtx,vector<std::vector<int> > graph,int flag){
    if(visited[vtx]==1) return;
    if(vtx!=a && vtx!=b && flag==0)s1.insert(vtx);
    else if(vtx!=a && vtx!=b  && flag==1) s2.insert(vtx);
    visited[vtx]=1;
    for(auto j:graph[vtx]){
        dfs(j,graph,flag);
    }
}
int main(){
    optimizeIO();
    tc{
        int n,m,x,y;
        cin>>n>>m>>a>>b;
        std::vector<vector<int> > graph(n+1,vector<int> ());
        rep(i,1,n+1) visited[i]=0;
        rep(i,0,m){
            cin>>x>>y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        dfs(a,graph,0);
        rep(i,1,n+1) visited[i]=0;
        dfs(b,graph,1);
        // cout<<s1.size()<<" "<<s2.size()<<endl;
        set<int> s3,s4;
        for(auto i:s1){
            // if(s2.find(i)==s2.end())s3.insert(i);
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:s2){
            // if(s1.find(i)==s1.end())s4.insert(i);
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<s1.size()*s2.size()<<endl;
        // s1.clear();
        // s2.clear();
    }
}