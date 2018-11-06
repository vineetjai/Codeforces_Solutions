#include <iostream>
using namespace std;
int main(){
	double n;
	cin>>n;
	double i=1;
	while(1){
		if((i*(i+1)/4.0*((2*i+1)/3.0+1.0))==n){
			cout<<i<<endl;break;
		}
		if((i*(i+1)/4.0*((2*i+1)/3.0+1.0))>n){
			cout<<i-1<<endl;break;
		}
		i++;
	}
}