#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <list> 
#include <limits.h>
#include <algorithm>
#define ll long long 
using namespace std;

int main(){
	string s;
	cin>>s;
	int x=0,i;
	string g="";
	for(i=s.length()-1;i>0;i--){
		if(s[i]=='a') break;
		g+=s[i];
	}	
	reverse(g.begin(), g.end()); 
	int idx=i+1;
	string l="";
	for(i=0;i<idx;i++){
		if(s[i]!='a'){
			l+=s[i];
		}
	}
	if(l==g) cout<<s.substr(0,idx)<<endl;
	else{
		for(i=idx;i<s.length();i++){
			l+=s[i];
			g.replace(0,1,"");
			if(l==g){
				cout<<s.substr(0,i+1)<<endl;
				return 0;
			}
		}
		cout<<":(\n";
	}
	// int y=s.length()-2*x+1;
	// if(y>0)cout<<2*x-1<<endl;
	// else cout<<s.length()<<endl;
}