#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	string s,g;
	cin>>s;
	int c=0;
	for(int i=1;i<t;i++){
		cin>>g;
		if(g[0]==s[1]) c+=1;
		s=g;
	}
	cout<<c+1<<endl;
}