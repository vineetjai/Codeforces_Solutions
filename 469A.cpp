#include <iostream>
#include <set>
using namespace std;
int main(){
	int x,n,p,q;
	cin>>n;
	cin>>p;
	set <int> s;
	for(int i=0;i<p;i++){
		cin>>x;
		s.insert(x);
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>x;
		s.insert(x);
	}
	if(s.size()==n) cout<<"I become the guy.\n";
	else cout<<"Oh, my keyboard!\n";
}