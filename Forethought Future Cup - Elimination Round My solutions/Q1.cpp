#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <list> 
#include <limits.h>
#define ll long long 
using namespace std;

int main(){
	string s;
	cin>>s;
	int x=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='a') x+=1;
	}	
	int y=s.length()-2*x+1;
	if(y>0)cout<<2*x-1<<endl;
	else cout<<s.length()<<endl;
}