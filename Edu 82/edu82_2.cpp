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
const ll mod=1e9+7;
#define f first
#define s second
#define pii pair< int, int >
#define tc int t; cin >> t; while(t--)
using namespace std;

void optimizeIO(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
}  
ll solve(int n_c){
    ll ans=0;
    int n=n_c/2;
    ans=(n*(n+1));
    if(n_c%2) ans+= (n_c+1)/2;
    return ans%mod;
}
ll power(ll x,ll y){
    if(y<=0) return 1;
    ll z=power(x,y/2);
    if(y%2) return (((z*z)%mod)*x)%mod;
    else return ((z*z)%mod);
}
ll invmod(ll x){
    return power(x,mod-2);
}
int main(){
    optimizeIO();
    tc{
        ll n,g,b;
        cin>>n>>g>>b;
        if(n<=g){
            cout<<n<<endl;
            continue;
        }
        ll x=floor(((n+1)/2)/(g*1.0));
        ll ans=x*(g+b);
        ll z=(n+1)/2-(x)*g;
        if(z>0) ans+=z;
        else if(z==0)  ans-=b;
        cout<<max(ans,n)<<endl;
    }   
}