#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(i=a;i<=n;i++)
#define per(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
const int N=2e5+5;
bool vis[N];
vector<int>e[N];
int a[N],d[N],pos[N];
ll p[N];
struct dis
{
    int id,w;
    bool operator < (const dis &x) const
    {
        return w>x.w;
    }
};
priority_queue<dis>q;
void dijkstra(int u)
{
    int i,j,k,v;
    d[u]=0;
    p[u]=1;
    q.push(dis({u,0}));
    while(!q.empty())
    {
        u=q.top().id;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(i=0;i<e[u].size();i++)
        {
            v=e[u][i];
            if(d[v]>d[u]+1)
            {
                d[v]=d[u]+1;
                p[v]=1;
                q.push(dis({v,d[v]}));
            }
            else if(d[v]==d[u]+1)
            {
                p[v]++;
            }
        }
    }
}
 
int main()
{
    int n,m,i,j,k,num,sum,t,tot,sym,u,v;
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    rep(i,1,m) cin>>u>>v,e[v].push_back(u);
    cin>>k;
    rep(i,1,k) cin>>a[i],pos[a[i]]=i;
    memset(d,0x3f,sizeof d);
    dijkstra(a[k]);
    int ans1=0,ans2=0;
    rep(i,1,k-1)
    {
        if(d[a[i+1]]+1>d[a[i]]) ans1++,ans2++;
        else if(p[a[i]]>1) ans2++;
    }
    printf("%d %d\n",ans1,ans2);
   return 0;
}