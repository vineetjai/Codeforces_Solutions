#include <iostream>
#include <cmath>
#define ll long long 
using namespace std;
int main(){
	ll y;
	cin>>y;
	ll k=ceil(y/5.0)+1; 
	double x=log2(k);
	ll h=ceil(x);
	if(h>1) y=y-5*(pow(2,h-1)-1);
	if(y<=pow(2,h-1)) cout<<"Sheldon\n";
	else if(y<=pow(2,h-1)*2)cout<<"Leonard\n";
	else if(y<=pow(2,h-1)*3)cout<<"Penny\n";
	else if(y<=pow(2,h-1)*4)cout<<"Rajesh\n";
	else if(y<=pow(2,h-1)*5)cout<<"Howard\n";
}