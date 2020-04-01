#include <iostream>
#include <bitset>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int a[m];
	for(int i=0;i<m;i++) cin>>a[i];
	int l;
	cin>>l;
	int c=0;
	for(int i=0;i<m;i++){
		int z=l^a[i];
		bitset<20> b1(z); 
		if(b1.count()<=k){
			c++;
		}
	}
	cout<<c<<endl;
}