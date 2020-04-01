#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main(){
	long long  n;
	cin>>n;
	long long  b[n];
	map<long long ,long long  >m;
	for(long long  i=0;i<n;i++){cin>>b[i]; m[b[i]]++;}
	sort(b,b+n);
	if(b[0]!=b[n-1]){
		long long x=m[b[0]]*m[b[n-1]];
		cout<<b[n-1]-b[0]<<" "<<x<<endl;
	}
	else{
		long long x=m[b[0]]*(m[b[0]]-1)/2;
		cout<<0<<" "<<x<<endl;
	}
}