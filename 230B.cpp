#include <iostream>
#include <cmath>
#define ll long long 
using namespace std;
int main(){
	int n;
	cin>>n;
	ll x;
	int p[1000000]={0};
	int k=0;
	for(int i=2;i<1000000;i++){
		int c=0;
		for(int j=2;j<=sqrt(i);j++){
			if(i%j==0) {c+=1; break;}
		}
		if(c==0) {p[i]=1;}
	}

	for(int i=0;i<n;i++){
		cin>>x;
		if(ceil(sqrt(x))*ceil(sqrt(x))!=x){
			cout<<"NO\n";
		}
		else{
			int c=0;
			int flag=0;
			if(p[(ll)(sqrt(x))]==1) flag=1;
			
			if(flag==1)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}