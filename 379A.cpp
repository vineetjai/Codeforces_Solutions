#include <iostream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int ans=a;
	int b1=a,b2=0;
	while(1){
		if((b1+b2)/b==0) break;
		else {
			int z=(b1+b2);
			ans+=z/b;
			b1=(z)/b;
			b2=(z)%b;
		}
	}
	cout<<ans<<endl;
}