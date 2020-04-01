// #include <iostream>
// #include <vector>
// #include <queue> //priority queue
// #include <stack>
// #include <map> // multimap
// #include <set> //multiset
// #include <list> 
// #include <utility> // pair
// #include <iterator>
// #include <deque> // insertion as both ends
// #include <string>
// // g1=s.substr(0,n/2);
// // g2=s.substr(n/2+n%2,n/2);
// #include <cctype> //isaplha
// #include <iomanip>      // std::setprecision
// #include <algorithm> //binary_search,sort, next_permutation in lexicographically greater permutation, fill(it1,it2,val)
// #include <cmath>
// #include <limits.h> //INT_MIN,INT_MAX
// #include <numeric>  //iota,partial_sum,inner_product,accumulate(begin,end,num)
// #include <functional>  //Arithmetic, comparators, logical
// #include <bitset>
// #include <unordered_map>
// #include <unordered_set>
// #include <stdio.h> 
// #include <cstring>
// #include <string>
// #include <sstream>
// #include <iostream>
// // #include <bits/stdc++.h>
// #define rep(i,a,b) for(int i=a;i<b;i++)
// #define rrep(i,b,a) for(int i=b;i>=a;i--)
// #define fori(a) for(auto i : a )
// #define all(a) begin(a), end(a)
// #define set(a,b) memset(a,b,sizeof(a))
// #define pi 3.14159
// #define ll long long 
// #define ull unsigned long long
// #define pb push_back
// #define PF push_front //deque
// #define mp make_pair
// #define pq priority_queue
// #define mod 1000000007
// #define f first
// #define s second
// #define pii pair< int, int >
// #define tc int t; cin >> t; while(t--)

// using namespace std;
// string repeat(string s, int n) {
//     string s1 = s; 
//     for (int i=1; i<n;i++) 
//         s += s1;
//     return s; 
// }
// string getString(char x) {
//     string s(1, x); 
//     return s;    
// } 

// void optimizeIO(){
//     ios_base::sync_with_stdio(false); 
//     cin.tie(NULL);
//     cout.tie(NULL);
// }
// int gcd(int a, int b){ 
//     if (a == 0)  return b; 
//     return gcd(b % a, a); 
// } 
// vector<ll> primeFactors(ll n)  { 
//     vector<ll> v;
//     if(n%2==0) v.pb(2); 
//     while (n % 2 == 0)  {  
//         n = n/2;  
//     }  
//     for (ll i = 3; i <= sqrt(n); i = i + 2) {  
//         if(n%i==0) v.pb(i);
//         while (n % i == 0) {  
//             n = n/i;  
//         }  
//     } 
//     if (n > 2)  v.pb(n);
//     return v;
// }  
// struct dsu {
//     vector<int> par, rank;
//     dsu(int n,vector<int> v): par(n+1), rank(n+1) {
//         for (int i = 1; i <= n; i++) {
//             par[i] = i;
//             rank[i]= -mod;
//         }
//     }
//     int root(int a) {
//         if (a == par[a]) return a;
//         return par[a] = root(par[a]);
//     }
//     void merge(int a, int b) {
//         a = root(a);
//         b = root(b);
//         if (a == b) return;
//         if (rank[a] > rank[b]) swap(a, b);
//         // rank[a] += rank[b];
//         par[b] = a;
//     }
//     set<int> parent(int n){
//         set<int> s;
//         for(int i=1;i<=n;i++){
//             s.insert(root(i));
//         }
//         return s;
//     }
// };
// // int n, m, v;
// // struct edge
// // {
// //     int a, b, cost;
// //     edge(int x,int y){
// //         this->a=x;
// //         this->b=y;
// //         this->cost=1;
// //     }
// // };
// // vector<edge> e;
// // const int INF = 1000000000;
// // void solve()
// // {   
// //     vector<int> d (n+1, INF);
// //     d[v] = 0;
// //     for (;;)
// //     {
// //         bool any = false;

// //         for (int j=0; j<m; ++j)

// //             if (d[e[j].a] < INF)
// //                 if (d[e[j].b] > d[e[j].a] + e[j].cost)
// //                 {   
// //                     d[e[j].b] = d[e[j].a] + e[j].cost;
// //                     any = true;
// //                 }
// //         // cout<<any<<endl;
// //         if (!any) break;
// //     }
// // }
// int depth[1002];
// vector<int> adj[1002];
// void dfs(int v,int p){
//     for(int i:adj[v]){
//         if(!depth[i]){
//             depth[i]=depth[v]+1;
//             dfs(i,v);
//         }
//     }
// }
// set<int> s;
// void dfs1(int v,int p,int lca){
//     if(v==lca) return ;
//     for(auto i:adj[v]){
//         if(i!=p && i!=lca){
//             s.erase(i);
//             dfs1(i,v,lca);
//         }
//     }
// }
// int main(){
//     optimizeIO();
//     int n,x,y;
//     cin>>n;
//     rep(i,0,n-1){
//         cin>>x>>y;
//         adj[x].pb(y);
//         adj[y].pb(x);
//     }
//     depth[1]=0;
//     dfs(1,0);
    
//     rep(i,1,n+1) s.insert(i);
//     priority_queue<pair<int,pair<int,int>>> pq;
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             pq.push({abs(depth[i]-depth[j]),{i+1,j+1}});
//         }
//     }
//     while(!pq.empty()){
//         pair<int,pair<int,int>> x=pq.top();
//         pq.pop();
//         int fir=x.s.f,sec=x.s.s;
//         if(s.find(fir)==s.end() || s.find(sec)==s.end()){
//             continue;
//         }
//         cout<<"? "<<x.s.f<<" "<<x.s.s<<endl;
//         cout.flush();
//         int lca;
//         cin>>lca;
//         if(lca==x.s.f){

//             s.erase(x.s.s);

//             for(int i:adj[x.s.s]){
//                 if(i!=lca){
//                    dfs1(i,x.s.s,lca);
//                 }
//             }
//         }
//         // dfs1(lca,)
//         else if(lca==x.s.s){
//             s.erase(x.s.f);
//             for(int i:adj[x.s.f]){
//                 if(i!=lca){
//                     dfs1(i,x.s.f,lca);
//                 }
//             }
//         }
//         else if(lca!=x.s.f && lca!=x.s.s){
//             s.erase(x.s.s);
//             for(int i:adj[x.s.s]){
//                 if(i!=lca){
//                     dfs1(i,x.s.s,lca);
//                 }
//             }
//             s.erase(x.s.f);
//             for(int i:adj[x.s.f]){
//                 if(i!=lca){
//                     dfs1(i,x.s.f,lca);
//                 }
//             }
//         }
//         if(s.size()==1){
//             cout<<"! "<<*s.begin()<<endl;
//             return 0;
//         }
//     }
//     if(s.size()==1){
//             cout<<"! "<<*s.begin()<<endl;
//             return 0;
//         }
// }

#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int> > edges;
 
set<int> bad;
 
void ask(int u, int v, int w){
    cout << "? " << u + 1 << " " << v + 1 << '\n';
    cout << flush;
    int ans;
    cin >> ans;
    ans--;
    assert(ans == u || ans == v || ans == w);
    if(ans != u) bad.insert(u);
    if(ans != v) bad.insert(v);
    if(ans != w) bad.insert(w);
}
 
int dfs(int v, int p){
    vector<int> nc;
    for(int w : edges[v]){
        if(w == p) continue;
        int z = dfs(w, v);
        if(z != -1) nc.push_back(z);
    }
    int ret = v;
    if(nc.size() % 2 == 1){
        ret = -1;
        nc.push_back((p == -1) ? v : p);
    }
    for(int i = 0; i < (int)nc.size(); i += 2){
        ask(nc[i], nc[i+1], v);
    }
    return ret;
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    edges.resize(n);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(0, -1);
    assert((int)bad.size() == (n-1));
    for(int i = 0; i < n; i++){
        if(!bad.count(i)){
            cout << "! " << i + 1 << '\n';
            cout << flush;
        }
    }
}