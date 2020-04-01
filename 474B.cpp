#include <iostream>
using namespace std;
int binary(int a[],int q,int n,int st,int en){
	if(en==st) return a[st];
	else if(en==st+1){
		if(q<=a[st]) return st;
		else return en;
	}
	else {
		int m=(st+en)/2;
		if(q==a[m]) return m;
		if(q>a[m]) st=m;
		else en=m;
		
	}
	// cout<<st<<" "<<en<<endl;
	return binary(a,q,n,st,en);
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		a[i]+=a[i-1];
	}
	int m;
	cin>>m;
	int q[m];
	for(int i=0;i<m;i++) cin>>q[i];
	for(int i=0;i<m;i++){
		cout<<binary(a,q[i],n,0,n-1)+1<<endl;
	}
}