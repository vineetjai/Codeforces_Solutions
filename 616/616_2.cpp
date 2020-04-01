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
bool check(std::vector<int> a){
    int flag=0,flag1=0;
    bool ans=1;
    rep(i,0,a.size()) if(a[i]==-1) return false;
    rep(i,1,a.size()){
        if(flag==0){
            if(a[i]==a[i-1]) return false;
            if(a[i]<a[i-1]) flag=1,flag1=1;
        }
        if(flag1==1){
            if(a[i]>=a[i-1]) return false;
        }
    }
    return true;
}
bool check1(int a[],int n){
    int flag=true,flag1=true;
    rep(i,0,n){
        if(a[i]<i) {flag=false; break;}
    }
    rrep(i,n-1,0){
        if(a[i]<n-1-i){
            flag1=false;
            break;
        }
    }
    return flag || flag1;
}
int main(){
    optimizeIO();
    tc{
        int n;
        cin>>n;
        int a[n];
        rep(i,0,n) cin>>a[i];
        std::vector<int> v(n,-1);
        if(n==1 || check1(a,n)) cout<<"Yes\n";
        else{
            v[0]=0;
            int idx=0;
            rep(i,1,n){
                if(a[i]>=v[i-1]+1) v[i]=v[i-1]+1;
                else {idx=i;break;}
            }
            if(idx>=1) v[idx-1]=a[idx-1];
            if(idx<=n-1) v[n-1]=0;
            rrep(i,n-2,idx){
                if(a[i]>=v[i+1]+1) v[i]=v[i+1]+1;
            }
            // rep(i,0,n) cout<<v[i]<<" ";
            // cout<<endl;
            if(check(v)) cout<<"Yes\n";
            else cout<<"No\n";
        }

    }
}