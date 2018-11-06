#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long 
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int n,a,b,m;
	cin>>n>>m>>a>>b;
	int min1=n*a;
	for(int i=1;i<=ceil(n/(float)m);i++){
		int l;
		if((n-i*m)*a <= 0) l=0;
		else l=(n-i*m)*a;
		min1=min(l+i*b,min1);
	}
	cout<<min1<<endl;
}