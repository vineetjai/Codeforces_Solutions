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
      int n,m;
      cin>>n>>m;
      int a[n+1];
      set<int> s;
      rep(i,1,n+1) {cin>>a[i];s.insert(a[i]);}
      int mx=*max_element(a+1,a+n+1);
      int mn=*min_element(a+1,a+n+1);
      int sum1=0;
      if(s.size()>m){
        cout<<-1<<endl;
      }
      else{
        int z=m-s.size();
        rep(i,1,n+1){
          if(z==0) break;
          s.insert(i);
          z=m-s.size();
        }

        cout<<(n)*(s.size())<<endl;
        rep(j,0,n){
          for(auto i:s) cout<<i<<" ";
        }
        cout<<endl;
      }
    }
}
