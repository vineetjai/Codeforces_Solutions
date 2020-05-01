#include <bits/stdc++.h>
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
ll power(ll x,ll y){
    if(y<=0) return 1;
    ll z=power(x,y/2);
    if(y%2) return (((z*z)%mod)*x)%mod;
    else return ((z*z)%mod);
}
ll invmod(ll x){
    return power(x,mod-2);
}
string solve(string s){
  int n=s.length();
  string g=s.substr(0,2);
  int j=0;
  for(int i=2;i<n;){
    if(s[i]==s[j]){
      g+=s[i];
      i++;
      j++;
    }
    else{
      g+=s[j];
      j++;
    }
  }
  return g;
}
bool check(string s){
  int n=s.length();
  rep(i,2,n){
    if(s[i]!=s[i-2]) return false;
  }
  return true;
}
string getString(char x) {
    string s(1, x);
    return s;
}
int main(){
    optimizeIO();
    tc{
      string s;
  		cin>>s;
  		int res1 = 0,res2 = 0;
  		for(int i = 0; i<s.size();i++){
  			if(s[i] == '1')res1++;
  			else res2++;
  		}
  		if(!res1||!res2)cout<<s<<endl;
  		else{
  			string res;
  			if(s[0] == '0')res+='0';
  			else res+='1';
  			for(int i = 1; i<s.size(); i++){
  				if(s[i]-'0' == !(res.back()-'0'))res+=s[i];
  				else{
  					if(res.back() == '0')res+='1';
  					else res+='0';
  					res+=s[i];
  				}
  			}
  			cout<<res<<endl;
  		}
    }
}
