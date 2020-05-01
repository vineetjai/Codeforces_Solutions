#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
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
bool solve(ll x){
  if(x&(x-1)) return false;
  return true;
}
int main(){
    optimizeIO();
    tc{
      ll n,k;
      cin>>n>>k;
      ll a[n];
      rep(i,0,n) cin>>a[i];
      ll mx=0,l=0;
      ll ans=0;
      rep(i,1,k-1) if(a[i]>a[i-1] && a[i]>a[i+1]) ans++;
      if(ans>mx) mx=ans;
      rep(i,k,n){
        if(i-2>=0 && a[i-1]>a[i-2] && a[i-1]>a[i]) ans++;
        if(a[i-k+1]>a[i-k+2] && a[i-k+1]>a[i-k]) ans--;
        if(ans>mx) mx=ans,l=i-k+1;
      }
      cout<<min(mx+1,k)<<" "<<l+1<<endl;
    }
}
