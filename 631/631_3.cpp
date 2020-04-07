#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int a[m];
  long long sum=0;
  vector<pair<int,int>>v;
  for(int i=0;i<m;i++){
    cin>>a[i];
    v.push_back({a[i],i});
    sum+=a[i];
  }
  if(sum<n){
    cout<<-1<<endl;
    return 0;
  }
  int made=0,haveto=n;

  int b[m];
  int flag=0;
  int st=0;
  for(int i=0;i<m;i++){
    b[v[i].second]=st+1;
    sum=sum-v[i].first;
    st=max(n-st-sum,1*1LL)+st;
  }

  for(int i=0;i<m;i++){
      if(b[i]-1+a[i]>n) flag=1;
  }

  if(flag){
    cout<<-1<<endl;
    return 0;
  }

  for(int i=0;i<m;i++){
    cout<<b[i]<<' ';
  }
  cout<<endl;
}
