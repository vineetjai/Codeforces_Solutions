#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<string> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  auto comp=[](string &x ,string &y){return x.length()<y.length();};
  sort(v.begin(),v.end(),comp);
  string ans;
  cin>>ans;
  int i=0,final=0;
  while(v[i].length()<ans.length()){
    final++;
    if((i+1)%k==0) final+=5;
    i++;
  }
  int mn=final+1,mx=final;
  map<string ,int> m;
  for(int j=i;j<n && v[j].length()==ans.length();j++) m[v[j]]++;
  int xf=0;
  for(auto i:m)if(i.first!=ans) xf+=i.second;

  while(xf>0){
    if((i+1)%k==0) mx+=5;
    mx++;
    i++;
    xf--;
  }
  cout<<mn<<" "<<mx+1<<endl;
}
