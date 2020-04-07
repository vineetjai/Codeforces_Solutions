#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie();
  int t;
  cin>>t;
  while(t--){
    int h,g,x;
    cin>>h>>g;
    int n=(1<<h)-1,m=(1<<g)-1;

    // 1 based indexing is done
    vector<pair<int,int>> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>x;
        v[i]={x,i};
    }

    // sorting with minimum
    sort(v.begin(),v.end());

    // fill that in final tree which position is already taken just like visited
    vector<int> tree(n+1,0);

    // for putting answer. used[i]=1 mean that this ith function call need to be done. total 2^g-1 function call will happen
    vector<int> used(n+1,0);

    // stroing sum
    long long sum=0;

    // getting m numbers
    for(int j=1;j<=n;j++){

      // minimum which will be taken or not
      int i=v[j].second;

      // check if bound in final tree is out of limit or if final tree ith postion is already taken
      while(i>m || tree[i]) i=i/2;

      // all position in path form i to 1 is already taken
      if(i==0) continue;

      // check
      // if 2*i>m then tree[2*i]==tree[2*i+1]==0
      // else tree[2*i]==tree[2*i+1]==1 taken

      // if 2*i<m tree[2*i]!=tree[2*i+1] then one of {2*i,2*i+1} is not taken, so first it needs to be filled.
      if(tree[2*i]==tree[2*i+1]){
        // filling ith postion in final tree
        tree[i]=1;
        // used this  v[j].second function calls
        used[v[j].second]=1;
        // adding it to sums
        sum+=v[j].first;
      }
    }
    cout<<sum<<'\n';
    // bottom to top call
    for(int i=n;i>=1;i--) if(!used[i]) cout<<i<<" ";
    cout<<'\n';
  }
}
