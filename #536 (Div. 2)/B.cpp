#include<iostream>
#include<map>
#include<utility>
#define ll long long
using namespace std;
int main(){
	ll i,n,m,t,d;
	cin>>n>>m;
	ll a[n],c[n];
	map<pair<ll,ll>,ll> :: iterator it;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<n;i++) cin>>c[i];
	map < pair <ll,ll> ,ll> m1;
	for(i=0;i<n;i++){
		m1[make_pair(c[i],i)]=a[i];
	}
	while(m--){
		cin>>t>>d;
		if(m1[make_pair(c[t-1],t-1)]>d){
			m1[make_pair(c[t-1],t-1)]-=d;
			cout<<c[t-1]*d<<endl;
		}
		else{
			ll c1=m1[make_pair(c[t-1],t-1)]*c[t-1];
			d-=m1[make_pair(c[t-1],t-1)];
			it=m1.find(make_pair(c[t-1],t-1));
			m1.erase (it);
			ll flag=0;
			while(d>0){
				if(m1.begin()!=m1.end()){
					if(m1.begin()->second>d){
						m1.begin()->second-=d;
						c1+=(m1.begin()->first).first*d;
						d=0;
					}
					else{
						c1+=((m1.begin()->first).first)*m1.begin()->second;
						d-=m1.begin()->second;
						m1.erase (m1.begin());
					}
				}
				else {
					flag=1;
					break;
				}
			}
			if(flag==1) cout<<0<<endl;
			else cout<<c1<<endl;
		}
	}
}