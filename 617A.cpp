#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;
int main(){
	int x;
	cin>>x;
	int dp[x+1];
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=1;
	dp[5]=1;
	for(int i=6;i<=x;i++){
		vector<int> v;
		v.pb(dp[i-5]+1);
		v.pb(dp[i-4]+1);
		v.pb(dp[i-3]+1);
		v.pb(dp[i-2]+1);
		v.pb(dp[i-1]+1);
		dp[i]= *min_element(v.begin(),v.end());
	}
	cout<<dp[x]<<endl;
}