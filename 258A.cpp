#include <iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int i=0,flag=0;
	for(;i<s.length()-1;i++){
		if(s[i]=='0'){
			flag=1;
			break;
		}
		else{
			cout<<s[i];
		}
	}
	if(flag==0){
		cout<<endl;
		return 0;
	}
	else{
		for(int j=i+1;j<s.length();j++) cout<<s[j];
		cout<<endl;
	}
}