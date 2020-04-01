#include<iostream>
#include <map>
using namespace std;
int main(){
	int n,m1;
	cin>>n>>m1;
	map<string,string> m;
	string g,h;
	for(int i=0;i<m1;i++){
		cin>>g>>h;
		if(g.length()<=h.length()) m[g]=g;
		else m[g]=h;	
	}
	for(int i=0;i<n;i++){
		cin>>g;
		cout<<m[g]<<" ";
	}
	cout<<endl;
}