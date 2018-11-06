#include <iostream>
#include <cmath>
using namespace std;
bool iscomposite(int p,int q){
	int f1=0,f2=0;
	for(int i=2;i<=sqrt(q);i++){
		if(q%i==0){f1=1; break;}
	}
	for(int i=2;i<=sqrt(p);i++){
		if(p%i==0){f2=1; break;}
	}
	if(f1==1 && f2==1) return true;
	else return false;
}
int main(int argc, char const *argv[]){
	int n;
	cin>>n;
	int i=4;
	while(1){
		if(iscomposite(i,n-i)){
			cout<<i<<" "<<n-i<<endl;
			break;
		}
		i++;	
	}
	return 0;
}