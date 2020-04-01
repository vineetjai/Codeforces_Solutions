#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long 
#define pb push_back
using namespace std;
int main(){
	ll n,k,x;
	cin>>n>>k;
	ll visited[n];
	std::vector<ll> v;
	for (ll i = 0; i < n; ++i){
		cin>>x;
		v.pb(x);
		visited[i]=-1;
	}
	int idx=max_element(v.begin(),v.end())-v.begin();	
	ll start=1;
	for(int i=max(0,(idx-k));i<min(n,idx+k);i++){
		visited[i]=1;
	}
}