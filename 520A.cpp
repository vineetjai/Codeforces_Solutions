#include <iostream>
#include <set>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	set<int >s1;
	for(int i=0;i<s.length();i++){
		s1.insert(tolower(s[i]));
	}
	if(s1.size()==26) cout<<"YES\n";
	else cout<<"NO\n";
}