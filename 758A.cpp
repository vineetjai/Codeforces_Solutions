#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define pb push_back
using namespace std;
int main(){
	int n;
	cin>>n;
	ll x;
	vector < ll > v1;
	for(int i=0;i<n;i++) {cin>>x;v1.pb(x);}
	sort(v1.begin(),v1.end());
	ll max1=v1[n-1],ans=0;
	for(int i=0;i<n;i++){
		ans+=(max1-v1[i]);
	}
	cout<<ans<<endl;
}