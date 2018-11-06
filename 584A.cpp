#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,t;
	cin>>n>>t;

	string s;
	s=to_string(t);
	if(n==1 && t==10)cout<<-1<<endl;
	else{
		if(t==10) n=n-1;
		for(int i=1;i<n;i++){
			s+=to_string(0);
		}
		cout<<s<<endl;
	}
}