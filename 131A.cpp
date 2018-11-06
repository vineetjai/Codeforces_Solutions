#include <iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int flag=0;
	for(int i=1;i<s.length();i++){
		if(!(s[i]-'A'>=0 && s[i]-'A'<=26)) {flag=1;break;} 
	}
	if(flag==1) cout<<s<<endl;
	else{
		for(int i=0;i<s.length();i++){
			if (islower(s[i])) {s[i]=toupper(s[i]);}
			else {s[i]=tolower(s[i]);}
		}
		cout<<s<<endl;
	}
}