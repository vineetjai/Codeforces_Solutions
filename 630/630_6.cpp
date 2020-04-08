#include<bits/stdc++.h>
#define int long long
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
#define debug cout<<"potxdy"<<endl;
using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=300007;
const int mod=998244353;

int n,dp[maxn][2],f[maxn];
VI vec[maxn];

int mult(int u,int v){
    u=(u%mod+mod)%mod, v=(v%mod+mod)%mod;
    return 1ll*u*v%mod;
}

void dfs(int u,int p){
    dp[u][0]=dp[u][1]=f[u]=1;
    for (auto c:vec[u]){
        if (c==p) continue;
        dfs(c,u);
        dp[u][0]=mult(dp[u][0],2*dp[c][0]+2*dp[c][1]-f[c]);
        dp[u][1]=mult(dp[u][1],dp[c][1]+2*dp[c][0]-f[c]);
        f[u]=mult(f[u],dp[c][0]+dp[c][1]-f[c]);
    }
}
//https://codeforces.com/blog/entry/75432?#comment-595676  explained a lot
#undef int
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        vec[u].pb(v), vec[v].pb(u);
    }
    dfs(1,0);
    cout<<(dp[1][0]+dp[1][1]-f[1]-1+2*mod)%mod<<endl;
    return 0;
}
