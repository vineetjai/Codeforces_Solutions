#include <iostream>
using namespace std;
int gcd(int a, int b) { 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int main(){
	int a,b,n;
	cin>>a>>b>>n;
	while(1){
		if(n!=0) n=n-gcd(a,n);
		if(n==0) {cout<<0<<endl;break;}
		if(n!=0) n=n-gcd(b,n);
		if(n==0){cout<<1<<endl;break;}
	}
}