#include <iostream>
#include <cmath>
using  namespace std;
int main(){
	int a[3],b[3];
	cin>>a[0]>>a[1]>>a[2];
	cin>>b[0]>>b[1]>>b[2];
	int n;
	cin>>n;
	int x=a[0]+a[1]+a[2],y=b[0]+b[1]+b[2];
	int z=ceil(x/5.0)+ceil(y/10.0);
	// cout<<z<<endl;
	if(z>n) cout<<"NO\n";
	else cout<<"YES\n";
}