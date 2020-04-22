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
  ll y=log2(x);
  ll z=ceil(log2(x*1.0));
  if(y==z) return true;
  return false;
}
int main(){
    optimizeIO();
    tc{
      ll n;
      cin>>n;
      ll x=1;
      // while(n%2==0) n/=2,x*=2;
      for(ll i=1;i<=sqrt(n)+1;i++){
        if(n%i==0){
          if(solve(i+1) && i!=1){
            x=n/i;
            break;
          }
          if(solve(n/i+1) && n/i !=1){
            x=i;
            break;
          }
        }
      }
      cout<<x<<endl;
    }
}
