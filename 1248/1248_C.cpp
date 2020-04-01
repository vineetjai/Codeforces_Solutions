#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=200005;
const ll mod=1e9+7;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll n,m,f[N][2];
int main()
{
	cin>>n>>m;
	f[1][0]=1;
	for(int i=2;i<=max(n, m);i++){
		(f[i][1]=f[i-1][0])%=mod;
		(f[i][0]=f[i-1][0]+f[i-1][1])%=mod;
	}
	ll ans0=(f[n][0]+f[n][1]-1+mod)%mod;
	ll ans1=(f[m][0]+f[m][1]-1+mod)%mod;
	ll ans=(ans0+ans1+1)*2ll%mod;
//	cout<<"gg "<<ans0<<' '<<ans1<<endl;
	cout<<ans<<endl;
	return 0; 
}

// ans=(fib(n)+fib(m)-1)*2