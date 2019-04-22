#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int dist[200005];
long long sum[200005];
long long f(long long x)
{
    return x*(x+1)/2;
}
int main()
{
    int m,a,b;
    scanf("%d%d%d",&m,&a,&b);
    int g=__gcd(a,b),n=min(m,a+b-1);
    for (int i=0;i<=n;i++)
    dist[i]=n+1;
    set<pair<int,int> > s;
    s.insert({0,0});
    dist[0]=0;
    while (!s.empty())
    {
        auto p=*s.begin();
        s.erase(s.begin());
        if (dist[p.second]!=p.first)
        continue;
        sum[p.first]++;
        if (p.second>=b && p.first<dist[p.second-b])
        {
            dist[p.second-b]=p.first;
            s.insert({p.first,p.second-b});
        }
        if (p.second+a<=n && max(p.first,p.second+a)<dist[p.second+a])
        {
            dist[p.second+a]=max(p.first,p.second+a);
            s.insert({max(p.first,p.second+a),p.second+a});
        }
    }
    long long ans=0;
    for (int i=0;i<=n;i++)
    {
        if (i)
        sum[i]+=sum[i-1];
        ans+=sum[i];
    }
    if (n!=m)
    {
        while ((m+1)%g)
        {
            ans+=m/g+1;
            m--;
        }
        ans+=g*(f(m/g+1)-f(n/g+1));
    }
    printf("%I64d",ans);
}
