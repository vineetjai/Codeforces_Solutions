#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	vector<int> v;
	v.pb((b+c)*a);
	v.pb((a+b)*c);
	v.pb(a*b*c);
	v.pb(a+b+c);
	v.pb(a+b*c);
	v.pb(a*b+c);
	cout<<*max_element(v.begin(),v.end())<<endl;
}