#include <iostream>
#define ll long long
using namespace std;
int main(){
	int n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int dp[n];
	for(int i=0;i<n;i++) dp[i]=1;
	int i,j;
	for (i = 1; i < n; i++ ){
		if(a[i]>=a[i-1]) dp[i]=dp[i-1]+1;
		else dp[i]=1;
	}
  	int max1=0;
    for (i = 0; i < n; i++ ) if (max1 < dp[i]) max1 = dp[i]; 
    cout<<max1<<endl;
}