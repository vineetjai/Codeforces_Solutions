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
int main(){
    optimizeIO();
    tc{
        ll n,m1;
        cin>>n>>m1;
        ll t[n],l[n],h[n];
        map<ll,vector<pair<ll,ll> > > m;
        rep(i,0,n){
            cin>>t[i]>>l[i]>>h[i];
            m[t[i]].pb({l[i],h[i]});
        }
        ll st=0;
        int flag=0;
        ll old_l=m1,old_h=m1;
        for(auto i:m){
            ll time=i.first;
            ll low=INT_MIN,high=INT_MAX;
            for(auto j:i.second){
                low=max(j.first,low);
                high=min(high,j.second);
            }
            old_l-=(time-st);
            old_h+=(time-st);
            st=time;
            old_l=max(old_l,low);
            old_h=min(old_h,high);
            if(old_l>old_h || high<low){
                cout<<"NO\n";
                flag=1;
                break;
            }
        }
        if(flag) continue;
        cout<<"YES\n";
    }
}