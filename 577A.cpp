#include <iostream>
using namespace std;
int main(){
	int n;
	long long x;
	cin>>n>>x;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(x%i==0 && x/i<=n) ans+=1;
	}
	cout<<ans<<endl;
}