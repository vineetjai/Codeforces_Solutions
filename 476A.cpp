#include <iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int flag=0;
	for(int i=0;i<=n;i++){
		if(i+2*((n-i)/2) == n && (i+(n-i)/2)%m==0){ flag=1;cout<<(i+(n-i)/2)<<endl;break;}
	}	
	if(flag==0) cout<<-1<<endl;
}