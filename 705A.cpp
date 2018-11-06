#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string s="I hate",g=" that I love",h=" that I hate",ans="";
	ans=s;
	for(int i=2;i<=n;i++){
		if(i%2==0) ans+=g;
		else ans+=h;
	}
	ans=ans+" it";
	cout<<ans<<endl;
}