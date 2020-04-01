#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#define ll long long 
#define pb push_back
using namespace std;
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){  
    return (a*b)/gcd(a, b);  
} 
int main(){
	ll n,i,j;
	cin>>n;
	ll a[n],b[n];
	for(i=0;i<n;i++) {cin>>a[i];b[i]=a[i];}
	sort(a,a+n);
	ll ans=INT_MAX;
	pair<ll,ll> l;
	for(j=0;j<n;j++){
		// ll x=lcm(a[j],a[j+1]);
		// // ans=min(x,ans);
		// if(x<ans){x=ans;l=make_pair(a[j],a[j+1]);}
		for(i=1;i<n;i++){
			ll y=lcm(a[i],a[j]);
			// if(a[i]%a[0]==0 && a[i]<x) {x=a[i];l=make_pair(a[0],a[i]);};
			if(y<ans){ans=y;l=make_pair(a[i],a[j]);}
		}
	}
	ll idx1 = distance(b,find(b, b + n, l.first));
	ll idx2 = distance(b,find(b, b + n, l.second));
	cout<<min(idx1,idx2)+1<<" "<<max(idx1,idx2)+1<<endl;
}