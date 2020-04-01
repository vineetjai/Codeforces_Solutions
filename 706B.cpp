#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;
// ll binary(vector<ll> v,ll q,ll st, ll en){
// 	// cout<<st<<".  "<<en<<endl;
// 	if(st+1==en){
// 		if(v[en]<=q) return en+1;
// 		else if(v[st]<=q) return st+1;
// 		return 0;
// 	} 
// 	else if(st==en){
// 		if(v[en]<=q) return en+1;
// 		return 0;
// 	}
// 	else{
// 		ll m=(st+en)/2;
// 		if(v[m]<=q) st=m;
// 		else en=m;
// 	}
// 	return binary(v,q,st,en);
// }
int main(){
	ll n,i,q;
	cin>>n;
	vector<ll> a(n);

	for(i=0;i<n;i++) cin>>a[i];

	sort(a.begin(),a.end());

	cin>>q;
	ll m[q];

	for(i=0;i<q;i++)cin>>m[i];

	for(i=0;i<q;i++)
		cout<<upper_bound(a.begin(), a.end(), m[i]) - a.begin()<<endl;
}