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
vector<ll> primeFactors(ll n)  { 
    vector<ll> v;
    if(n%2==0) v.pb(2); 
    while (n % 2 == 0)  {  
        n = n/2;  
    }  
    for (ll i = 3; i <= sqrt(n); i = i + 2) {  
        if(n%i==0) v.pb(i);
        while (n % i == 0) {  
            n = n/i;  
        }  
    } 
    if (n > 2)  v.pb(n);
    return v;
}  
struct dsu {
    vector<int> par, rank;
    dsu(int n,vector<int> v): par(n+1), rank(n+1) {
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            rank[i]= -mod;
        }
    }
    int root(int a) {
        if (a == par[a]) return a;
        return par[a] = root(par[a]);
    }
    void merge(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) return;
        if (rank[a] > rank[b]) swap(a, b);
        // rank[a] += rank[b];
        par[b] = a;
    }
    set<int> parent(int n){
        set<int> s;
        for(int i=1;i<=n;i++){
            s.insert(root(i));
        }
        return s;
    }
};
const int INF=INT_MAX;
void dijkstra(int s, vector<int> & d, vector<int> & p,vector<int> adj[],int n) {
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge;
            int len = 1;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}
vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}
int main(){
    optimizeIO();
    int n,m,k,x,y;
    cin>>n>>m>>k;
    vector<int> v(k);
    set<int> s;
    rep(i,0,k) cin>>v[i];
    rep(i,0,k) s.insert(v[i]);
    vector<int> adj[n];
    rep(i,0,m){
        cin>>x>>y;
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1);
    }
    vector<int> dis,p;
    dijkstra(0,dis,p,adj,n);
    vector<int> path=restore_path(0,n-1,p);
    rep(i,0,path.size()) path[i]++;
    int mx=INT_MAX,st=-1,en=-1;
    int gl_st=-1,gl_en=-1;
    rep(i,0,path.size()){
        if(s.find(path[i])!=s.end()){
            if(st==-1){
                st=i;
            }
            else if(en==-1){
                en=i;
            }
            else{
                
                if(mx>en-st){
                    gl_st=st;
                    gl_en=en;
                }
                mx=min(mx,en-st);
                swap(en,st);
                en=i;
            }
        }
    }
    if(mx>en-st){
                    gl_st=st;
                    gl_en=en;
                }
    set<int> s1;
    rep(i,0,path.size()){
        s1.insert(path[i]);
    }
    // int falg=1;
    // rep(i,1,path.size()){
    //     if(s.find(path[i])!=s.end() && s.find(path[i-1])!=s.end()){
    //         falg=1;
    //         break;
    //     }
    // }
    // if(falg){
    //     cout<<path.size()<<endl;
    //     return 0;
    // }
    // cout<<gl_st<<" "<<gl_en<<endl;
    if(gl_st==-1 || gl_en==-1){
        cout<<path.size()-1<<endl;
    }
    else{
        cout<<(path.size()-abs(gl_en-gl_st-1)-1)<<endl;
    }
}