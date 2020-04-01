#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long a[n],s=0;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		s+=abs(a[i]-i-1);
	}
	cout<<s<<endl;
}