#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int main(){
	vector< vector <char> > v;
	vector<char> v1,v2,v3;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++) v1.pb('#');
	for(int i=0;i<m-1;i++)v2.pb('.');
	v2.pb('#');v3.pb('#');
	for(int i=1;i<m;i++)v3.pb('.');
	for(int i=0;i<n;i++){
		if(i%2==0) v.pb(v1);
		else{
			if(i%4==1) v.pb(v2);
			else v.pb(v3);
		}
	}
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j];
		cout<<endl;
	}
}