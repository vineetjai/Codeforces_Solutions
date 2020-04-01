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
            rank[i]= v[i];
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
void findReachable() {
    // dsu d(n);
    // for (int k = g + 1; k <= n; k++) {
    //     for (int x = 2 * k; x <= n; x += k) {
    //         d.merge(x - 1, x - k - 1);
    //     }
    // }

    // int m = from.size();
    // vector<int> ans;
    // for (int i = 0; i < m; i++) {
    //     ans.push_back(d.root(from[i] - 1) == d.root(to[i] - 1));
    // }
    // return ans;
    int n,m,x,y;
    cin>>n>>m;
    vector<pii> v;
    rep(i,0,m){
        cin>>x>>y;
        v.pb({x,y});
    }
    vector<int>rank(n+1);
    rep(i,1,n+1) cin>>rank[i];
    dsu d(n,rank);
    rep(i,0,m) d.merge(v[i].f,v[i].s);
    set<int>s=d.parent(n);
    ll ans=0;
    for(auto i:s) ans+=rank[i];
    cout<<ans<<endl;
}
bool check(string s){
    rep(i,1,s.length()){
        if(s[i]==s[i-1]) return false;
    }
    return true;
}
int main(){
    optimizeIO();
    tc{
        string s;
        cin>>s;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                if(i==0){
                    int l=-1;
                    if(i+1<n)l=s[i+1]-'a';
                    if(l==-1) s[i]='a';
                    else{
                        if(l!=0) s[i]='a';
                        else s[i]='b';
                    }
                }
                else if(i==n-1){
                    int l=-1;
                    if(i-1>=0)l=s[i-1]-'a';
                    if(l==-1) s[i]='a';
                    else{
                        if(l!=0) s[i]='a';
                        else s[i]='b';
                    }   
                }
                else{
                    int l=s[i+1]-'a'+s[i-1]-'a';
                    if(s[i+1]=='a' && s[i-1]=='c'){
                        s[i]='b';
                    }
                    else if(s[i+1]=='b' && s[i-1]=='c'){
                        s[i]='a';
                    }
                    else  if(s[i+1]=='a' && s[i-1]=='b'){
                        s[i]='c';
                    }
                    else  if(s[i+1]=='a' && s[i-1]=='a'){
                        s[i]='b';
                    }
                    else  if(s[i+1]=='c' && s[i-1]=='c'){
                        s[i]='b';
                    }
                    else  if(s[i+1]=='b' && s[i-1]=='b'){
                        s[i]='a';
                    }
                    else  if(s[i+1]=='c' && s[i-1]=='a'){
                        s[i]='b';
                    }
                    else  if(s[i+1]=='c' && s[i-1]=='b'){
                        s[i]='a';
                    }
                    else  if(s[i+1]=='b' && s[i-1]=='a'){
                        s[i]='c';
                    }
                    else if(s[i+1]=='?'){
                         int l=-1;
                        if(i-1>=0)l=s[i-1]-'a';
                        if(l==-1) s[i]='a';
                        else{
                            if(l!=0) s[i]='a';
                            else s[i]='b';
                        }  
                    }
                    else{
                        int l=-1;
                        if(i+1<n)l=s[i+1]-'a';
                        if(l==-1) s[i]='a';
                        else{
                            if(l!=0) s[i]='a';
                            else s[i]='b';
                        }
                    }
                }   
            }
        }
        if(!check(s)) cout<<-1<<endl;
        else cout<<s<<endl;
    }
}