#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(ll i=b;i>=a;i--)
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
#define pii pair< ll, ll >
#define tc ll t; cin >> t; while(t--)
using namespace std;

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
ll solve(ll x,ll lcm,ll mx){
  ll llr=(x/lcm)*lcm;
  ll ans=x;
  ans-=mx*(x/lcm);
  rep(i,llr,min(mx+llr,x+1)) ans--;
  return ans;
}
int main(){
    optimizeIO();
    tc{
      ll a,b,q;
      cin>>a>>b>>q;
      ll lcm=(a*b)/__gcd(a,b);
      ll mx=max(a,b),mn=min(a,b);
      while(q--){
        ll l,r;
        cin>>l>>r;
        ll ans=solve(r,lcm,mx)-solve(l-1,lcm,mx);
        cout<<ans<<" ";
      }
      cout<<endl;
    }
}
