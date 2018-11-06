#include <iostream>
using namespace std;
int main(){
	int n,m,x,y;
	cin>>n>>m;
	cin>>x;
	long long c=x-1;
	for(int i=1;i<m;i++){
		cin>>y;
		if(y>=x) c+=(y-x);
		else c+=(n-x+y);
		x=y;
	}
	cout<<c<<endl;
}