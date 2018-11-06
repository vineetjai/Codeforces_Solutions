#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	cout<<n+floor(((float)(n-1))/(m-1))<<endl;
}