
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,k;
int calc(int x){
    vector<pair<int,int> >range;
    range.push_back(make_pair(x,x+(x%2==0)));
    while(range.back().second<=n){
        int l=range.back().first,r=range.back().second;
        range.push_back(make_pair(l*2,r*2+1));
    }
    int ret=0;
    for(int i=0;i<range.size();i++){
        if(range[i].first<=n)ret+=min(range[i].second,n)-range[i].first+1;
    }
    return ret;
}
signed main(){
    cin>>n>>k;
    int L=0,R=n/2+1;
    while(R-L>1){
        int mid=(L+R)/2;
        if(calc(mid*2)<k)R=mid;
        else L=mid;
    }
    int ans=L*2;
    L=0,R=n/2+2;
    while(R-L>1){
        int mid=(L+R)/2;
        if(calc(mid*2-1)<k)R=mid;
        else L=mid;
    }
    ans=max(ans,L*2-1);
    cout<<ans<<endl;
    return 0;
}