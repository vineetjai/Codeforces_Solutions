#include <iostream>
using namespace std;
int main(){
	string s,g,ans="";
	cin>>s>>g;
	for(int i=0;i<s.length();i++){
		if(s[i]==g[i]) ans+="0";
		else ans+="1";
	}
	cout<<ans<<endl;
}