#include <iostream>
using namespace std;
int main(){
	int n,x;
	cin>>n;
	int c=0,ans=0;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x>0) c+=x;
		else {
			if(c>0) c-=1;
			else ans+=1;
		}
	}
	cout<<ans<<endl;
}