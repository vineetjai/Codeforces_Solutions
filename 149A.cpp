#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int q,x;
	cin>>q;
	vector<int> v;
	for(int i=0;i<12;i++){
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int ans=0,id=0;
	if(q<=ans){
		cout<<id<<endl;
		return 0;
	}
	for(int i=11;i>=0;i--){
		ans+=v[i];
		id++;
		if(q<=ans){
			cout<<id<<endl;
			return 0;
		}
	}	
	cout<<-1<<endl;
}