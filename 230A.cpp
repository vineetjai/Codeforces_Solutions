#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;
int main(){
	int s,n,x,y;
	cin>>s>>n;
	vector< pair <int,int> > v;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		v.pb(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	int flag=1;
	for(int i=0;i<n;i++){
		if(s>v[i].first) s+=v[i].second;
		else {flag=0;break;}
	}
	if(flag) cout<<"YES\n";
	else cout<<"NO\n";
}