#include <iostream>
#include <string>
using namespace std;
int main(){
	string  n;
	cin>>n;
	int x=stoi(n);
	int flag=1;
	int l=0,m=0;
	for(int i=0;i<n.length();i++){
		if(n[i]=='4' ) {l+=1;}
		else if(n[i]=='7') m+=1;
		if(n[i]!='7' && n[i]!='4'){flag=0; break;}
	}
	int flag1=-1;
	int a[10]={4,7, 44, 47,74,77,447,474,477,444};
	for(int i=0;i<10;i++){
		if(x%a[i]==0) {flag1=1; break;}
	}
	if(flag1==1 || flag==1 ) cout<<"YES\n";
	else cout<<"NO\n";
}