// #include <iostream>
// #include <vector>
// #include <queue>
// #include <map>
// #include <utility>
// #include <list> 
// #include <limits.h>
// #include <algorithm>
// #include <cmath>
// #define ll long long 
// #define mk make_pair
// #define pb push_back
// using namespace std;

// int func(std::vector<pair<int,int> >  v){
// 	int c=0;
// 	for(int i=0;i<v.size();i++){
// 		cout<<v[i].first<<" "<<v[i].second<<endl;
// 		c+=v[i].second-v[i].first+1;
// 	}
// 	return c;
// }
// int main(){
// 	int t,n,max2;
// 	cin>>t;
// 	while(t--){
// 		cin>>n;
// 		// vector<pair<pair<int,int> , pair<int,int> > > v;
// 		// v.push_back(make_pair(1,n/2),make_pair(int(ceil(n/2.0)),n));
// 		int max1=INT_MIN,max2;
// 		vector < pair<int,int> > v1,v2,v3,v4;
// 		v1.pb(mk(1,n/2));
// 		v2.pb(mk(int(ceil(n/2.0)),n));
// 		cout<<v1[0].second-v1[0].first+1<<" "<<v2[0].second-v2[0].first+1<<" ";
// 		for(int i=0;i<v1.size();i++){
// 			for(int j=v1[i].first;j<=v1[i].second;j++){
// 				cout<<j<<" ";
// 			}
// 		}
// 		for(int i=0;i<v2.size();i++){
// 			for(int j=v2[i].first;j<=v2[i].second;j++){
// 				cout<<j<<" ";
// 			}
// 		}
// 		cout<<endl;
// 		cin>>max2;
// 		max1=max(max2,max1);
// 		cout.flush();

// 		while(1){
// 			v3.clear();
// 			v4.clear();
// 			int flag=0;
// 			int x=0;
// 			for(int i=0;i<v1.size();i++){
// 				if(v1[i].second%2==0) x=1;
// 				if(x==1){
// 					v3.pb(mk(v1[i].first,v1[i].second/2-1));
// 					v4.pb(mk(int(ceil(v1[i].second/2.0)),v1[i].second));
// 					if((v1[i].first==v1[i].second/2-1 && ceil(v1[i].second/2.0)==v1[i].second)) flag=1;
// 				}
// 				else {
// 					v3.pb(mk(v1[i].first,v1[i].second/2));
// 					v4.pb(mk(int(ceil(v1[i].second/2.0)),v1[i].second));
// 					if((v1[i].first==v1[i].second/2 && ceil(v1[i].second/2.0)==v1[i].second)) flag=1;
// 				}
				
// 			}
// 			x=0;
// 			for(int i=0;i<v2.size();i++){
// 				if(v1[i].second%2==0) x=1;
// 				if(x==1){
// 					v3.pb(mk(v2[i].first,v2[i].second/2-1));
// 					v4.pb(mk(int(ceil(v2[i].second/2.0)),v2[i].second));
// 					if((v2[i].first==v2[i].second/2-1 && ceil(v2[i].second/2.0)==v2[i].second)) flag=1;
// 				}

// 				else {
// 					v3.pb(mk(v2[i].first,v2[i].second/2));
// 					v4.pb(mk(int(ceil(v2[i].second/2.0)),v2[i].second));
// 					if((v2[i].first==v2[i].second/2 && ceil(v2[i].second/2.0)==v2[i].second)) flag=1;
// 				}
				
// 			}
// 			if(flag) break;
// 			cout<< func(v3)<<" "<<func(v4)<<" ";
// 			for(int i=0;i<v3.size();i++){
// 				for(int j=v3[i].first;j<=v3[i].second;j++){
// 					cout<<j<<" ";
// 				}
// 			}
// 			for(int i=0;i<v4.size();i++){
// 				for(int j=v4[i].first;j<=v4[i].second;j++){
// 					cout<<j<<" ";
// 				}
// 			}
// 			cout<<endl;
// 			cin>>max2;
// 			max1=max(max2,max1);
// 			cout.flush();
// 			if(flag) break;
// 			v1=v3;
// 			v2=v4;
// 		}
// 		cout<<-1<<" "<<max2<<endl;

// 	}
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int ask(int u, const vector<int>& b) {
  cout << 1 << ' ' << (int) b.size() << ' ' << u;
  for (int x : b) {
    cout << ' ' << x;
  }
  cout << endl;
  int d;
  cin >> d;
  return d;
}

void solve() {
  int n;
  cin >> n;
  vector<int> b(n - 1);
  iota(b.begin(), b.end(), 2);
  int r = ask(1, b);
  while ((int) b.size() > 1) {
    vector<int> b1 = b;
    b1.resize((int) b.size() / 2);
    if (ask(1, b1) == r) {
      b = b1;
    } else {
      b.erase(b.begin(), b.begin() + (int) b.size() / 2);
    }
  }
  int v = b[0];
  b.clear();
  for (int i = 1; i <= n; ++i) {
    if (i != v) {
      b.push_back(i);
    }
  }
  int res = ask(v, b);
  cout << -1 << ' ' << res << endl;
}

signed main() {
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}