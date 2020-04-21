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

vector<vector<int>> adj;
vector<bool> vis;
int k;
vector<int> size1(200001,1);
set<pair<int,int>,greater<pair<int,int>>> st1;
vector<int> mark;
ll ans=0;

void dfs(int v,int high){
  vis[v]=true;
  for(auto i:adj[v]){
    if(!vis[i]){
      dfs(i,high+1);
      size1[v]+=size1[i];
    }
  }
  st1.insert({high-size1[v]+1,v});
}

int dfs1(int v){
  vis[v]=true;
  int x=0;
  for(auto i:adj[v]){
    if(!vis[i]){
      x+=dfs1(i);
    }
  }
  if(mark[v]==0) ans+=x;
  if(mark[v]==1) x++;
  return x;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,x,y;
  cin>>n>>k;
  adj.assign(n,vector<int>());
  vis.assign(n,false);
  mark.assign(n,0);

  rep(i,0,n-1) {cin>>x>>y; adj[x-1].pb(y-1);adj[y-1].pb(x-1);}

  dfs(0,1);

  while(k--){
    auto i=*st1.begin();
    mark[i.second]=1;
    st1.erase(st1.begin());
  }

  vis.assign(n,false);
  dfs1(0);
  cout<<ans<<endl;
}
