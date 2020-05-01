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
const ll mod=998244353;
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
ll mult(ll a, ll b){
	return a * 1ll * b % mod;
}
int main(){
    optimizeIO();

    ll d;
    cin>>d;

    vector<ll> primes;
    for(ll i=2;i*i<=d;i++)
      if(d%i==0){
        primes.pb(i);
        while(d%i==0) d=d/i;
      }
    if(d>1) primes.pb(d);

    // calculating factorial and inverse factorial
    int N=100; // N=50 also works but take 100 it doesn't make much diffrence in execution time
    vector<ll> fact(N),revfact(N);
    fact[0]=1,revfact[0]=1;
    for(ll i=1;i<N;i++){
      fact[i]=mult(fact[i-1],i);
      // inefficient approach to calculate invmod of fcatorial, time=1497ms
      // revfact[i]=mult(revfact[i-1],power(i,mod-2));
    }
    // also little bit efficent approach, time=1482ms
    revfact[N-1]=power(fact[N-1],mod-2);
    for(int i=N-2;i>=0;i--){
      revfact[i]=mult(revfact[i+1],i+1);
    }

    tc{
      ll u,v;
      cin>>u>>v;

      // path is optimal if u->gcd(u,v)->v
      // so for u->gcd(u,v) number of ways to go is ((p1+p2+p3+...pn)!)/(p1!p2!p3!....pn!) same for gcd(u,v)->v
      // multioly both and get answer

      ll x=__gcd(u,v);
      u=u/x;
      v=v/x;
      vector<ll> down,up;
      for(auto i:primes){
        ll cnt=0;
        while(u%i==0){
          ++cnt;
          u=u/i;
        }
        if(cnt>0) down.pb(cnt);

        cnt=0;
        while(v%i==0){
          ++cnt;
          v=v/i;
        }
        if(cnt>0) up.pb(cnt);
      }
      ll ans=1;
      ans=mult(fact[accumulate(all(down),0)],ans);
      ans=mult(ans,fact[accumulate(all(up),0)]);
      for(auto i:down) ans=mult(ans,revfact[i]);
      for(auto i: up) ans=mult(ans,revfact[i]);
      cout<<ans<<endl;
    }
}
