#include <iostream>
#include <map>
using namespace std;
int main(){
	int x;
	map<char,int> m;
	for(int i=0;i<4;i++){
		cin>>x;
		m['0'+i+1]=x;
	}
	string g;
	cin>>g;
	long long ans=0;
	for(int i=0;i<g.length();i++){
		ans+=m[g[i]];
	}
	cout<<ans<<endl;
}