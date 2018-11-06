#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	string g,s;
	cin>>s>>g;
	reverse(s.begin(), s.end());
	if(g == s) cout<<"YES\n";
	else cout<<"NO\n";
}