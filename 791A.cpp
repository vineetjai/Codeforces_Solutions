#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	// cout<<float(float(log(a/float(b)))/log(3/2.0))<<endl;
	int z=ceil(float(log(b/float(a)))/log(3/2.0));
	if(a*pow(3,z)==b*pow(2,z)) z+=1;
	cout<<z<<endl;
}