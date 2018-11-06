#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int n,a,b,c,left1,left2;
	cin>>n>>a>>b>>c;
	int max1=-10;
	for(int i=0;i<=(n/a);i++){
		left1=n-i*a;
		for(int j=0;j<=(left1/b);j++){
			left2=left1-j*b;
			if(left2%c==0) {max1=max(max1,j+i+left2/c);}
		}
	}
	cout<<max1<<endl;
}