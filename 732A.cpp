#include <iostream>
using namespace std;
int main(){
	int k,r;
	cin>>k>>r;
	int i=1;
	while( 1){
		if(i*k %10==0 || i*k%10==r){cout<<i<<endl;break;}
		i++;
	}
}