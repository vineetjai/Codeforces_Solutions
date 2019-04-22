#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long 
#define pb push_back
using namespace std;
int main(){
	int n,x;
	cin>>n;
	vector<int > v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.pb(x);
	}
	sort(v.begin(),v.end());
	set<int> s;
	s.insert(v[0]);
	s.insert(v[n-1]);
	int l=v[v.size()-1]-v[0];
	int ans;
	if(l%2==0) ans=l/2;
	else ans=-1;
	for(int i=1;i<n-1;i++){
		s.insert(v[i]);
	}
	if(s.size()<=3){
		set<int>::iterator it = s.begin();
		it++;
		// cout<<*it<<endl; 
		if(s.size()==3 && *it!=ans+v[0]) ans=-1;
		if(s.size()==2 && ans==-1) ans=v[n-1]-v[0];
	}
	else{
		ans=-1;
	}
	cout<<ans<<endl;
}