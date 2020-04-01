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
std::vector<int> prime;
void sv()
{
    vector<bool> mark(10001,true);
    mark[0] = mark[1] = false;
    for(int i = 2; i*i<10001; i++)
    {
        if(mark[i])for(int j = i*i; j<10001; j+=i)mark[j] = false;
    }
    rep(i,0,10001)if(mark[i])prime.pb(i);
}
vector<pair<pair<int,int>,int>> ans;
void fnc(int c){
	rep(j,1,3*c){
		vector<int> v;
		v.pb(1);
		for (int i=1; i<=sqrt(j); i++) 
	        if (j%i == 0){ 
	            if (j/i == i) 
	                v.push_back(i);
	  
	            else {
	            	v.pb(i);
	            	v.pb(j/i);
	            }
	        }
	    sort(all(v));
		rep(i,0,v.size()){
			rep(k,i,v.size()){
				if(v[k]==v[i] || v[k]%v[i]==0 ){
					int a=v[i],b=v[k];
					if(j%v[k]==0)ans.pb({{a,b},j});
				}
			}
		}
    }
}
int main(){
    optimizeIO();
    // fnc(10001);
    // int n=3,m=3;
    // int a[3][3]={{6,2,0},{4, 2, 4},{6,6,2}};
    // int dp[n][m];
    // dp[0][0]=a[0][0];
    // rep(i,0,n){
    //     rep(j,0,m){
    //         if(i==0 && j==0) continue;
    //         if(i==0) dp[i][j]= dp[i][j-1]&a[i][j];
    //         else if(j==0) dp[i][j]= dp[i-1][j] & a[i][j];
    //         else dp[i][j]=max(dp[i][j-1]&a[i][j],dp[i-1][j] & a[i][j]);
    //     }
    // }
    // rep(i,0,n){
    //     rep(j,0,m){
    //        cout<<dp[i][j]<<" "; 
    //     }
    //     cout<<endl;
    // }
    int k;
    cin>>k;
    if(k==0){
        cout<<1<<" "<<1<<endl;
        cout<<30000<<endl;
        return 0;
    }
    int a[3][3];
    a[2][2]=k;
    a[2][0]=0;
    a[0][1]=k;
    a[1][1]=k;
    int pw= ceil(log2(k+0.1));
    int x=pow(2,pw)+k;
    a[0][0]=x;
    a[2][0]=x;
    a[2][1]=x;
    a[1][0]=x-k;
    a[1][2]=x-k;
    cout<<3<<" "<<3<<endl;
    rep(i,0,3){
        rep(j,0,3){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}