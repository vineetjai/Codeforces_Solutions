#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;
using ld = long double;

int ask(int a,std::vector<int> v){
	cout<<1<<" "<<v.size()<<" "<<a;
	for(int x:v){
		cout<<" "<<x;
	}
	cout<<endl;
	int y;
	cin>>y;
	return y;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n-1);
		iota(v.begin(),v.end(),2);
		int t,r=ask(1,v);
		while(v.size()>1){
			vector<int> v1=v;
			v1.resize((int) v.size()/2);
			if(r==ask(1,v1))
				v=v1;
			else
				v.erase(v.begin(),v.begin() + (int) v.size() / 2);
		}
		int d=v[0];
		v.clear();
		// v1.clear();
		for(int i=1;i<=n;i++){
			if(i!=d)
			v.push_back(i);
		}
		int ans=ask(d,v);
		cout<<-1<<" "<<ans<<endl;
	}
}