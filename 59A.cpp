#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	int c1=0,c2=0;
	for(int i=0;i<s.length();i++){
		if(isupper(s[i])) c1+=1;
		else c2+=1;
	}
	if(c2>=c1) transform(s.begin(), s.end(), s.begin(), ::tolower); 
	else transform(s.begin(), s.end(), s.begin(), ::toupper);
	cout<<s<<endl;
}