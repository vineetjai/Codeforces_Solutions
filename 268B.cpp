#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<n;i++){
		ans+=(n-i)*i;
	}
	ans+=n;
	cout<<ans<<endl;
}