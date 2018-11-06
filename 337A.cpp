#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int f[m];
	for(int i=0;i<m;i++){
		cin>>f[i];
	}
	sort(f,f+m);
	int min1 = 10000;
	for(int i=0,j=n-1;i<m-n+1,j<m;i++,j++){
		min1=min(f[j]-f[i],min1);
	}
	cout<<min1<<endl;
}