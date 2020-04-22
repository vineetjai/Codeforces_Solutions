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
vector<vector<int>> adj;
vector<int> par,vis;
int main(){
    optimizeIO();
    tc{
      int n,m,a,b,c;
        cin>>n>>m>>a>>b>>c;
        vector<ll> p(m),pre(m+1);
        for(int i=0;i<m;i++) cin>>p[i];
        sort(all(p));
        for(int i=1;i<=m;i++) pre[i]=pre[i-1]+p[i-1];
        vector<ll> adj[n+1];
        vector<vector<ll>> vis(3,vector<ll> (n+1,0)),dis(3,vector<ll> (n+1,0));
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        vector<ll> t={a,b,c};
        for(int i=0;i<3;i++){
            queue<ll> q;
            q.push(t[i]);
            vis[i][t[i]]=1;
            while(!q.empty()){
                auto v=q.front();
                q.pop();
                for(auto j:adj[v]){
                    if(vis[i][j]==0){
                        vis[i][j]=1;
                        dis[i][j]=dis[i][v]+1;
                        q.push(j);
                    }
                }
            }
        }
        ll mini=1ll<<60;
        for(int i=1;i<=n;i++){
                ll common=dis[1][i];
                ll distinct=dis[2][i]+dis[0][i];
                if(common+distinct<=m){
                    ll sum=pre[common]+pre[common+distinct];
                    mini=min(mini,sum);
                }
        }
        cout<<mini<<endl;
    }
}
