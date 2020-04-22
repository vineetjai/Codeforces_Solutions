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

int main(){
    optimizeIO();
    tc{
      int n,k;
      cin>>n>>k;
      int a[n];
      rep(i,0,n) cin>>a[i];
      vector<int> ch(2*k+2,0);
      for(int i = 0,j = n-1; i<j; i++,j--){
         int sum=a[i]+a[j],m1,m2;
          m1=min(a[i],a[j]);
          m2=max(a[i],a[j]);
          ch[2]+=2;
          ch[m1+1]-=1;
          ch[sum]-=1;
          ch[sum+1]++;
          ch[k+m2+1]++;
          ch[k*2+1]--;
      }
      for(int i = 2; i<=2*k ;i++) ch[i]+=ch[i-1];
      int minsum = -1;
      int minch = INT_MAX;
      for(int i = 2; i<=2*k; i++){
          if(ch[i]<minch){
              minch = ch[i];
              minsum = i;
          }
      }
      int ans = 0;
      for(int i = 0,j = n-1; i<j; i++,j--){
          if(a[i]+a[j]!=minsum){
              if(minsum-a[i]>=1&&minsum-a[i]<=k)ans+=1;
              else if(minsum-a[j]>=1&&minsum-a[j]<=k)ans+=1;
              else ans+=2;
          }
      }
      cout<<ans<<endl;

    }
}
