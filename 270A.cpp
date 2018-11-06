#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int t,a;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a;
		if(360 % (180-a)==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
}