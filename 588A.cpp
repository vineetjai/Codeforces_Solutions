#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a,p,p_;
	cin>>a>>p;
	long long s=0;
	s+=a*p;
	p_=p;
	for(int i=1;i<n;i++){
		cin>>a>>p;
		p_=min(p,p_);
		s+=a*p_;
	}
	cout<<s<<endl;
}