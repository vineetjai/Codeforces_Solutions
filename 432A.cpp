#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	vector<int >v;
	for(int i=0;i<n;i++){
		if(a[i]+k <= 5) v.pb(a[i]);
	}
	cout<<v.size()/3<<endl;
}