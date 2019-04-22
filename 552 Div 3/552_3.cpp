#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;
int main(){
	ll v[3];
	cin>>v[0]>>v[1]>>v[2];
	map<ll,ll> m;
	m[0]=0;
	m[1]=0;
	m[2]=1;
	m[3]=2;
	m[4]=0;
	m[5]=2;
	m[6]=1;
	ll x=min(min(v[0]/3,v[1]/2),v[2]/2);
	v[0]=v[0]-x*3;
	v[1]=v[1]-x*2;
	v[2]=v[2]-x*2;
	ll ans=x*7;
	for(ll i=0;i<=6;i++){
		ll idx=i;
		ll s=0;
		vector<ll> v2;
		v2.push_back(v[0]);
		v2.push_back(v[1]);
		v2.push_back(v[2]);
		while(1){
			if(idx>6){
				idx=idx-7;
			}
			if(v2[m[idx]]<=0){break;}
			else {s=s+1;v2[m[idx]]-=1;}
			idx++;
		}
		// cout<<s<<endl;
		ans=max(ans,s+x*7);
	}
	cout<<ans<<endl;
}