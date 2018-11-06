#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int max1=0,count=0,l=0;
	for(int i=0;i<n;i++){
		if(a[i]==1){ count=0;}
		else {count+=1;max1=max(max1,count);}
	}
	for(int i=0;i<n;i++){
		if(max1==count) l++;
		if(a[i]==1){ count=0;}
		else {count+=1;}
	}
	int ans=l*max1;
	for(int i=0;i<n;i++) if(a[i]==1) ans+=1;
	int c=0;
	for(int i=0;i<n;i++) if(a[i]==1) c+=1;
	if(c==n) cout<<c-1<<endl;
	else cout<<ans<<endl;
	}