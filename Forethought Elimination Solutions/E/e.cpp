#include <iostream>
#include <vector>
using namespace std;
#define sh 100000
vector<int> v[200005];
int arr[100005],tree[2][400005],ans[200005],cur=-sh;
pair<char,int> qu[100005];
void update(int node,int st,int en,int idx,pair<char,int> val)
{
    if (st==en)
    {
        tree[0][node]=0;
        if ((val.first=='>' && cur>val.second) || (val.first=='<' && cur<val.second))
        tree[0][node]=1;
        tree[1][node]=1;
        if ((val.first=='>' && -cur>val.second) || (val.first=='<' && -cur<val.second))
        tree[1][node]=0;
    }
    else
    {
        int mid=(st+en)/2;
        if (st<=idx && idx<=mid)
        update(2*node,st,mid,idx,val);
        else
        update(2*node+1,mid+1,en,idx,val);
        for (int i=0;i<2;i++)
        tree[i][node]=tree[tree[i][2*node]][2*node+1];
    }
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for (int i=0;i<q;i++)
    {
        scanf(" %c%d",&qu[i].first,&qu[i].second);
        if (qu[i].first=='>')
        {
            v[qu[i].second+1+sh].push_back(i);
            v[-qu[i].second+sh].push_back(i);
        }
        if (qu[i].first=='<')
        {
            v[qu[i].second+sh].push_back(i);
            v[-qu[i].second+1+sh].push_back(i);
        }
        update(1,0,q-1,i,qu[i]);
    }
    while (1)
    {
        ans[cur+sh]=tree[0][1];
        if (cur==sh)
        break;
        cur++;
        for (int i:v[cur+sh])
        update(1,0,q-1,i,qu[i]);
    }
    for (int i=0;i<n;i++)
    printf("%d ",(!ans[arr[i]+sh]-ans[arr[i]+sh])*arr[i]);
}
