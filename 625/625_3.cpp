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
bool find(char x,string g){
    for(auto i:g){
        if(i==x) return true;
    }
    return false;
}
string reduce(string g){
    char x='a';
    for(int i=0;i<g.length();i++){
        if(g[i]>x) x=g[i];
    }
    while(g.length()>0 && x>='a'){
        if(!find(x,g)){
            x--;
            continue;
        }
        int st=0,st1=0;
        string h="";
        
        for(int i=0;i<g.length();i++){
            if(g[i]==x-1){
                while(h.length()>0 && h[h.length()-1]==x){
                    h.erase(h.length()-1);
                }
                st=1;
                h+=g[i];
            }
            else if(g[i]==x && st==1){
                continue;
            }
            else{
                h+=g[i];
                st=0;
            }
        }
        g=h;
        x--;
    }

    return g;
}
int main(){
    optimizeIO();
    int n;
    cin>>n;
    string s;
    cin>>s;
    n=s.length();
    // vector<int> v;
    // if(s[0]!='a')v.push_back(0);
    //  string ans="",g="";
    //  int st=0;
    // rep(i,0,n){
    //     if(s[i]=='a' && st==1) {
    //         g+='a';
    //         string jk=reduce(g);
    //         ans+= st==1?jk.substr(1,jk.length()-1):jk;
    //         g="a";
    //     }
    //     else if(s[i]=='a' && st!=1){
    //         ans+=reduce(g+'a');
    //         g="a";
    //         st=1;
    //     }
    //     else{
    //         g+=s[i];
    //     }
    // }
    // if(s[n-1]!='a' ){
    //     string jk=reduce(g);
    //     ans+= st==1?jk.substr(1,jk.length()-1):jk;
    // }
    // cout<<n-ans.length()<<endl;

    for (char cur = 'z'; cur >= 'a'; --cur) {
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] != cur) {
                continue;
            }
 
            bool fl = false;
            if (i != 0 && s[i - 1] == s[i] - 1) {
                fl = true;
            }
            if (i != (int)s.size() - 1 && s[i + 1] == s[i] - 1) {
                fl = true;
            }
 
            if (fl) {
                s.erase(s.begin() + i);
                i = -1;
            }
        }
    }
 
    std::cout << n - (int)s.size() << '\n';
}