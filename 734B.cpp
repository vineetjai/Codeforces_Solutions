#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	long long k2,k3,k4,k5;
	cin>>k2>>k3>>k4>>k5;
	long long x=min(min(k2,k4),k5);
	k2=k2-x;
	cout<<x*256+min(k2,k3)*32<<endl;
}