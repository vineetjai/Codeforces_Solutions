#include <iostream>
#include <vector>
#include <queue> //priority queue
#include <stack>
#include <map> // multimap
#include <set> //multiset
#include <list>
#include <utility> // pair
#include <iterator>
#include <deque> // insertion as both ends
#include <string>
// g1=s.substr(0,n/2);
// g2=s.substr(n/2+n%2,n/2);
#include <cctype> //isaplha
#include <iomanip>      // std::setprecision
#include <algorithm> //binary_search,sort, next_permutation in lexicographically greater permutation, fill(it1,it2,val)
#include <cmath>
#include <limits.h> //INT_MIN,INT_MAX
#include <numeric>  //iota,partial_sum,inner_product,accumulate(begin,end,num)
#include <functional>  //Arithmetic, comparators, logical
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
// #include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define tc int t; cin >> t; while(t--)

using namespace std;
string repeat(string s, int n) {
    string s1 = s;
    for (int i=1; i<n;i++)
        s += s1;
    return s;
}
string getString(char x) {
    string s(1, x);
    return s;
}

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if (a == 0)  return b;
    return gcd(b % a, a);
}
vector<int> r,b,g;
int nr,ng,nb;
ll sum1,sum2,sum3;
pair<int,int> solveg(int x){
  auto itr=lower_bound(all(g),x);
  auto itr1=lower_bound(all(g),x);
  int j,k;
  if(itr==g.end()) j=ng-1;
  else j=itr-g.begin();
  if(itr1!=g.begin()) k=itr1-g.begin()-1;
  else k=itr1-g.begin();
  return {j,k};
}
pair<int,int> solver(int x){
  auto itr=lower_bound(all(r),x);
  auto itr1=lower_bound(all(r),x);
  int j,k;
  if(itr==r.end()) j=nr-1;
  else j=itr-r.begin();
  if(itr1!=r.begin()) k=itr1-r.begin()-1;
  else k=itr1-r.begin();
  return {j,k};
}
pair<int,int> solveb(int x){
  auto itr=lower_bound(all(b),x);
  auto itr1=lower_bound(all(b),x);
  int j,k;
  if(itr==b.end()) j=nb-1;
  else j=itr-b.begin();
  if(itr1!=b.begin()) k=itr1-b.begin()-1;
  else k=itr1-b.begin();
  return {j,k};
}
int main(){
    optimizeIO();
    tc{
      r.clear();
      b.clear();
      g.clear();
      sum1=LLONG_MAX;sum2=LLONG_MAX;sum3=LLONG_MAX;
      cin>>nr>>ng>>nb;
      int x;
      rep(i,0,nr) {
        cin>>x;
        r.pb(x);
      }
      rep(i,0,ng)  {
        cin>>x;
        g.pb(x);
      }
      rep(i,0,nb)  {
        cin>>x;
        b.pb(x);
      }
      sort(all(r));
      sort(all(g));
      sort(all(b));
      rep(i,0,nr){
        pii x= solveg(r[i]);
        pii z= solveb((g[x.f]+r[i])/2);
        pii w= solveb((g[x.s]+r[i])/2);
        pii z1= solveb((g[x.f]+r[i]+1)/2);
        pii w1= solveb((g[x.s]+r[i]+1)/2);

        pii y= solveb(r[i]);
        pii a= solveg((b[y.f]+r[i])/2);
        pii c=solveg((b[y.s]+r[i])/2);
        pii a1= solveg((b[y.f]+r[i]+1)/2);
        pii c1=solveg((b[y.s]+r[i]+1)/2);

        vector<ll> r1={r[i],r[i],r[i],r[i],r[i],r[i],r[i],r[i],r[i],r[i],r[i],r[i],r[i],r[i],r[i],r[i]};
        vector<ll> g1={g[x.f],g[x.s],g[x.f],g[x.s],g[x.f],g[x.s],g[x.f],g[x.s],g[a.f],g[a.s],g[a1.f],g[a1.s],g[c.f],g[c.s],g[c1.f],g[c1.s]};
        vector<ll> b1={b[z.f],b[z.s],b[z1.f],b[z1.s],b[w.f],b[w.s],b[w1.f],b[w1.s],b[y.f],b[y.s],b[y.f],b[y.s],b[y.f],b[y.s],b[y.f],b[y.s]};
        rep(j,0,g1.size()){
          sum1=min(sum1,(r1[j]-b1[j])*(r1[j]-b1[j])+(r1[j]-g1[j])*(r1[j]-g1[j])+(g1[j]-b1[j])*(g1[j]-b1[j]));
        }
      }
      rep(i,0,nb){
        pii x= solveg(b[i]);
        pii z= solver((g[x.f]+b[i])/2);
        pii w= solver((g[x.s]+b[i])/2);
        pii z1= solver((g[x.f]+b[i]+1)/2);
        pii w1= solver((g[x.s]+b[i]+1)/2);

        pii y= solver(b[i]);
        pii a= solveg((r[y.f]+b[i])/2);
        pii c=solveg((r[y.s]+b[i])/2);
        pii a1= solveg((r[y.f]+b[i]+1)/2);
        pii c1=solveg((r[y.s]+b[i]+1)/2);

        vector<ll> b1={b[i],b[i],b[i],b[i],b[i],b[i],b[i],b[i],b[i],b[i],b[i],b[i],b[i],b[i],b[i],b[i]};
        vector<ll> g1={g[x.f],g[x.s],g[x.f],g[x.s],g[x.f],g[x.s],g[x.f],g[x.s],g[a.f],g[a.s],g[a1.f],g[a1.s],g[c.f],g[c.s],g[c1.f],g[c1.s]};
        vector<ll> r1={r[z.f],r[z.s],r[z1.f],r[z1.s],r[w.f],r[w.s],r[w1.f],r[w1.s],r[y.f],r[y.s],r[y.f],r[y.s],r[y.f],r[y.s],r[y.f],r[y.s]};
        rep(j,0,b1.size()){
          sum1=min(sum1,(r1[j]-b1[j])*(r1[j]-b1[j])+(r1[j]-g1[j])*(r1[j]-g1[j])+(g1[j]-b1[j])*(g1[j]-b1[j]));
        }
      }
      rep(i,0,ng){
        pii x= solver(g[i]);
        pii z= solveb((r[x.f]+g[i])/2);
        pii w= solveb((r[x.s]+g[i])/2);
        pii z1= solveb((r[x.f]+g[i]+1)/2);
        pii w1= solveb((r[x.s]+g[i]+1)/2);

        pii y= solveb(g[i]);
        pii a= solver((b[y.f]+g[i])/2);
        pii c=solver((b[y.s]+g[i])/2);
        pii a1= solver((b[y.f]+g[i]+1)/2);
        pii c1=solver((b[y.s]+g[i]+1)/2);

        vector<ll> g1={g[i],g[i],g[i],g[i],g[i],g[i],g[i],g[i],g[i],g[i],g[i],g[i],g[i],g[i],g[i],g[i]};
        vector<ll> r1={r[x.f],r[x.s],r[x.f],r[x.s],r[x.f],r[x.s],r[x.f],r[x.s],r[a.f],r[a.s],r[a1.f],r[a1.s],r[c.f],r[c.s],r[c1.f],r[c1.s]};
        vector<ll> b1={b[z.f],b[z.s],b[z1.f],b[z1.s],b[w.f],b[w.s],b[w1.f],b[w1.s],b[y.f],b[y.s],b[y.f],b[y.s],b[y.f],b[y.s],b[y.f],b[y.s]};
        rep(j,0,g1.size()){
          sum1=min(sum1,(r1[j]-b1[j])*(r1[j]-b1[j])+(r1[j]-g1[j])*(r1[j]-g1[j])+(g1[j]-b1[j])*(g1[j]-b1[j]));
        }
      }
      cout<<sum1<<endl;
    }
}
