#include <iostream>
using namespace std;
int main(){
	int n,h,x;
	cin>>n>>h;
	int c=0;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x>h) c+=2;
		else c+=1;
	}
	cout<<c<<endl;
}