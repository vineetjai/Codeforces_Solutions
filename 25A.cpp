#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	vector< vector < int > > v;
	vector<int > v1,v2;
	v1.pb(-1100); v2.pb(-10000);
	v.pb(v1);v.pb(v2);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]%2==0) v[0].pb(i);
		else v[1].pb(i);
	}
	if(v[1].size()==2) cout<<v[1][1]+1<<endl;
	else cout<<v[0][1]+1<<endl;
}	