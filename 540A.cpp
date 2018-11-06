#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s,g;
	cin>>s>>g;
	long long ans=0;
	for(int i=0;i<s.length();i++){
		ans+=min(abs(s[i]-g[i]),(10-abs(g[i]-s[i])));
	}
	cout<<ans<<endl;
}