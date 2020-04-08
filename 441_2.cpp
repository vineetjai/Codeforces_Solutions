#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,v,x,y;
    cin>>n>>v;
    map<long long,long long> m;
    for(long long i=0;i<n;i++){
      cin>>x>>y;
      m[x]+=y;
    }
    vector<pair<long long,long long >> v1;
    for(auto i:m){v1.push_back({i.second,i.first});}
    long long last=0;
    long long ans=0;
    int t=1;
    for(long long i=0;i<v1.size();){
      if(v1[i].second==t){
        ans+=min(v1[i].first+last,v);
        last=min(v1[i].first+last-min(v1[i].first+last,v),(v1[i].first));
        i++;
        t++;
      }
      else{
        ans+=min(last,v);
        last=0;
        t=v1[i].second;
      }
    }
    ans+=min(last,v*1LL);
    cout<<ans<<endl;
    return 0;
}
