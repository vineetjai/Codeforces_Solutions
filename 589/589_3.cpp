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
#include <algorithm> //binary_search,sort, next_permutation in lexicographically greater permutation
#include <cmath>
#include <limits.h> //INT_MIN,INT_MAX
#include <numeric>  //iota,partial_sum,inner_product,accumulate(begin,end,num)
#include <functional>  //Arithmetic, comparators, logical
#include <bitset>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b-1;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))

#define ll long long 
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
void prime(ll x,vector<ll > &v){
    ll y=x;
    for(ll i=2;i<=y;i++){
        int z=i;
        if(x%z==0){
            ll ans=0;
            while(x%z==0 && x!=0){
                x=x/z;
            }
            v.push_back(i);
        }
    }
}

void primeFactors(ll n,set<ll> &s)  {  
    while (n % 2 == 0){  
        s.insert(2);
        n = n/2;  
    } 
    for (int i = 3; i <= sqrt(n); i = i + 2){  
        while (n % i == 0)  
        {  
            s.insert(i);
            n = n/i;  
        }  
    }  
    if (n > 2)  
        s.insert(n);
}  

ll power(ll x, ll y){ 
    if (y == 0) 
        return 1; 
    ll z=power(x, y / 2)%mod;
    if (y % 2 == 0) 
        return  (z*z)%mod; 
    else
        return (x *((z*z)%mod))%mod; 
} 

int main(){
	optimizeIO();
    ll x, n;
    cin>>x>>n;
    set<ll > v;
    primeFactors(x,v);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<endl;
    // }
    ll ans=1;
    set<ll> :: iterator it=v.begin();
    while(it!=v.end()){
        ll num=*it;
        ll fu=0;
        ll z=1;
        while(z<=n/num){
            z=z*num;
            fu+=(n/z);
        }

        fu=fu%(mod-1);
        // cout<<fu<<endl;
        ans=ans*power(num,fu);
        ans%=mod;
        it++;
    }
    cout<<ans<<endl;
	return 0;
}