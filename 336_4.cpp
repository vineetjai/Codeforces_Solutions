#include <bits/stdc++.h>
using namespace std;
int n;
int a[501];
int dp[501][501];
void solve(){
  // first all single elements will be filled with 1. then all substring with len=2 and then len=3 till len=n.
  // otherwise if we for(int i=0;i<n;i++) for(int j=i;j<n;j++) then answer will be wrong.
  // As for i==j it will be calculated correct by other terms will be zero due to no intial setupt of len=1 substring. 
  for(int len=1;len<=n;len++)
    for(int i=0,j=len-1;j<n;j++,i++){
      if(i==j) dp[i][j]=1;
      else{
        dp[i][j]=1+dp[i+1][j];
        if(a[i]==a[i+1]) dp[i][j]=min(dp[i][j],1+dp[i+2][j]);
        for(int k=i+2;k<=j;k++) if(a[i]==a[k]) dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k+1][j]);

      }
    }
    cout<<dp[0][n-1]<<endl;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  solve();
}
