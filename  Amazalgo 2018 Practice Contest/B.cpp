#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
#define ll long long 
using namespace std;
int gcd(int a,int b){
	if(a==0) return b;
	else gcd(b%a,a);
}
int main(){
	int a,b;
	cin>>a>>b;
	ll c;
	c=a*b/gcd(a,b);
	cout<<c<<endl;
}