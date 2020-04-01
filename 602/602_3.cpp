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
bool isPrime(ll n){
    if (n <= 1)  return false; 
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false; 
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
    return true; 
} 
pii solve1(int x, string s){
    string g=s.substr(x);
    int l=g.length(),c=0;
    std::vector<int> v,v1,v2;
    rep(i,0,l){
        if(g[i]=='('){
            c++;
            v.pb(i);
        }
    }
    // cout<<g<<endl;
    rep(i,0,l){
        if(g[i]=='('){
            if(i>=c) v1.pb(i);
        }
        else{
            if(!(i>=c)) v2.pb(i);
        }
    }
    cout<<v1.size()<<endl;
    rep(i,0,v1.size()){
        cout<<v1[i]+x+1<<" "<<v2[i]+x+1<<endl;
    }
}
int main(){
    optimizeIO();
    tc{
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        stack<pair<char,int> > st; 
        set<int> s1,s2;
        int i=1,a=0;
        st.push(mp(s[0],0));
        if(s[0]=='(') s1.insert(0);
        else s2.insert(0);
        vector<pii> v;
        while(i<n){
            if(st.empty()){
                a++;
                st.push(mp(s[i],i));
                if(s[i]=='(')s1.insert(i);
                else if(s[i]==')') s2.insert(i);
            }
            else{
                if(st.top().f=='(' && s[i]==')') {
                    pii x=st.top();
                    st.pop();
                    if(x.f=='(') s1.erase(x.s);
                    else s2.erase(x.s);
                    if(st.empty()){
                        v.pb(mp(x.s,i));
                    }
                }
                else {
                    st.push(mp(s[i],i));
                    if(s[i]=='(')s1.insert(i);
                    else if(s[i]==')') s2.insert(i);
                }
            }
            i++;
        }
        if(st.empty()){
                a++;
        }
        if(k==a){
            cout<<0<<endl;
        }
        else{
            int x=0;
            rep(i,0,n) if(s[i]=='(') x++;
            if(a==0){
                    // solve(0,s,k);
            }else{
                if(k>a){

                }else{
                    solve1(v[k-1].f,s);
                }
            }
        }
        
    }
}