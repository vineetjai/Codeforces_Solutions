#include<iostream>
using namespace std;
int main(){
	int i,j,n,c=0;
	cin>>n;
	char x[n][n];
	for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>x[i][j];
	for(i=1;i<n-1;i++){
		for(j=1;j<n-1;j++){
			if(x[i-1][j-1]=='X' && x[i+1][j+1]=='X' && x[i][j]=='X' && x[i-1][j+1]=='X' && x[i+1][j-1]=='X' ) c+=1;
		}
	}
	cout<<c<<endl;
}