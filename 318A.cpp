#include <iostream>
#define ll long long
using namespace std;
int main(){
	ll k,n;
	cin>>k>>n;
	if(k%2==0){
		if(n<=k/2) cout<<2*n-1<<endl;
		else cout<<2*(n-k/2)<<endl;
	}
	else{
		if(n<=(k/2+1)) cout<<2*n-1<<endl;
		else cout<<2*(n-k/2-1)<<endl;
	}
}