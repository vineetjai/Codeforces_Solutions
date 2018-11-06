#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
int main(){
	char str[1001];
	set<char> s;
	gets(str);
	int i=1;
	while(str[i]!='\0'){
		// cout<<str[i]<<endl;
		if(str[i]-'a'>=0 && 'z'-str[i]<=26){s.insert(str[i]);}
		i++;
	}
	// cout<<*(s.end())<<endl;
	cout<<s.size()-1<<endl;
}