#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	string s;
	cin>>s;
	int x=count(s.begin(),s.end(), 'A');
	int y=t-x;
	if(y>x) cout<<"Danik\n";
	else if(y<x) cout<<"Anton\n";
	else cout<<"Friendship\n";
}