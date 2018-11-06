#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int max1=*max_element(a,a+n);
	int min1=*min_element(a,a+n);
	int imax,imin;
	for(int i=0;i<n;i++){
		if(max1==a[i]){imax=i;break;}
	}
	for(int i=0;i<n;i++){
		if(min1==a[i]){imin=i;}
	}
	if(imin>imax){cout<<imax+n-1-imin<<endl;}
	else{
		cout<<imax+n-2-imin<<endl;
	}
}