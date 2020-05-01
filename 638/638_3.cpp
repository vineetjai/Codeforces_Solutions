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
string getString(char x,int n) {
    string s(n, x);
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
      string s;
      int n,k;
      cin>>n>>k;
      cin>>s;
      map<char,int> m;
      rep(i,0,s.length()) m[s[i]]++;
      vector<string> ans(k,"");
      int idx=0;
      int flag1 = (m.size()>=3 ? 1:0);

      while(idx<k){
        auto i=*m.begin();
        ans[idx]+=i.first;
        m[i.first]--;
        if(m[i.f]<=0) m.erase(i.first);
        idx++;
      }

      if(*min_element(all(s))==*max_element(all(s))){
        string ans1=ans[0];
        for(auto i:m) ans1=ans1+getString(i.f,(i.s+k-1)/k);
        cout<<ans1<<endl;
      }
      else if(ans[k-1]!=ans[0]){
        cout<<ans[k-1]<<endl;
      }
      else{
        int flag=0;
        for(auto i:m){
          if(i.s%k!=0 ) {flag=1;break;}
        }
        if(flag1 || m.size()!=1 ){
          string ans1=ans[0];
          for(auto i:m){
            ans1+=getString(i.f,i.s);
          }
          cout<<ans1<<endl;
        }
        else{
          string ans1=ans[0];
          for(auto i:m){
            ans1+=getString(i.f,(i.s+k-1)/k);
          }
          cout<<ans1<<endl;
        }
      }
    }
}
