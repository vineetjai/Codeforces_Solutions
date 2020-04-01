#include <iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x=n/2;
	long long ans=pow(2,x);
	if(n%2==0)cout<<ans<<endl;
	else cout<<0<<endl;
}