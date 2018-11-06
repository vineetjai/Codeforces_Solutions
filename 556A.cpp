#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int c1=0,c2=0;
	for(int i=0;i<s.length();i++) if(s[i]=='0') c1+=1; else c2+=1;
	cout<<abs(c1-c2)<<endl;
}