#include <iostream>
#include <set>
using namespace std;
int main(){
	int l,m,n,o;
	cin>>l>>m>>n>>o;
	set<int >s;
	s.insert(l);s.insert(m);s.insert(n);s.insert(o);
	cout<<4-s.size()<<endl;
}