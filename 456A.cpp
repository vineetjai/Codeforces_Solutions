#include<iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
	
	int x,y,n;
	cin>>n;
	pair<int,int> a[n];
	for(int i=0;i<n;i++){
		cin>>x>>y;
		a[i]=make_pair(x,y);
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		if(a[i].second<a[i-1].second){
			cout<<"Happy Alex\n";
			return 0;
		}
	}
	cout<<"Poor Alex\n";
}