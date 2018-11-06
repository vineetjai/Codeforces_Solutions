#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int z=((240-k)*2)/5;
	int flag=0;
	for(int i=1;i<=n;i++){
		if(i*(i+1)>z) {flag=1;cout<<i-1<<endl;break;}
		if(i*(i+1)==z){flag=1;cout<<i<<endl;break;}
	}
	if(flag==0) cout<<n<<endl;
}