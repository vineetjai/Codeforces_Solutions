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
int main(){
    optimizeIO();
    tc{
        int n;
        cin>>n;
        int a[n];
        rep(i,0,n) cin>>a[i];
        vector<int> v;
        rep(i,0,n){
            if(a[i]!=-1){
                if((i-1>=0 && a[i-1]==-1) || (i+1<n && a[i+1]==-1)){
                    v.pb(a[i]);
                }
            }
            if(a[i]!=-1 && i==0 && a[i+1]==-1){
                v.pb(a[i]);
            }
            else if(a[i]!=-1 && i==n-1 && a[i-1]==-1){
                v.pb(a[i]);
            }
        }
        ll x=v.size()>0 ?(*max_element(v.begin(),v.end())+*min_element(v.begin(),v.end()))/2:0;
        ll ans1=0;
        int b[n];
        rep(i,0,n){
            if(a[i]==-1) b[i]=x;
            else b[i]=a[i];
        }
        rep(i,0,n-1){
            ans1= max(ans1,1LL*abs(b[i]-b[i+1]));
        }

        cout<<ans1<<" "<<x<<endl;
    }
}