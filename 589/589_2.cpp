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
#include <algorithm> //binary_search,sort, next_permutation in lexicographically greater permutation
#include <cmath>
#include <limits.h> //INT_MIN,INT_MAX
#include <numeric>  //iota,partial_sum,inner_product,accumulate(begin,end,num)
#include <functional>  //Arithmetic, comparators, logical
#include <bitset>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b-1;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))

#define ll long long 
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
long long mod=1000000007;
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
ll power(ll x, ll y){ 
    if (y == 0) 
        return 1; 
    ll z=power(x, y / 2)%mod;
    if (y % 2 == 0) 
        return  (z*z)%mod; 
    else
        return (x *((z*z)%mod))%mod; 
} 
void optimizeIO(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
	optimizeIO();
    int h,w;
    cin>>h>>w;
    int r[h],c[w];
    rep(i,0,h) cin>>r[i];
    rep(i,0,w) cin>>c[i];
    int dp[h][w];
    rep(i,0,h) rep(j,0,w) dp[i][j]=-1;
    rep(i,0,h) {rep(j,0,r[i]) dp[i][j]=1; if(r[i]!=w) dp[i][r[i]]=0;}

    rep(i,0,w) {
        rep(j,0,c[i]) {
            if(dp[j][i]==0){

                cout<<0<<endl;
                return 0;
            }
            dp[j][i]=1;
        }
        // rep(j,0,w) cout<<dp[i][j]<<" ";
        // cout<<endl;cout

        if(c[i]!=h){
            if(dp[c[i]][i]==1){
                // cout<<i<<c[i]<<endl;
                // cout<<dp[i][c[i]]<<endl;
                cout<<0<<endl;
                return 0;
            }
            dp[c[i]][i]=0;
        }
        // rep(i,0,h) {rep(j,0,w) cout<<dp[i][j]<<" "; cout<<endl;}
    }

    int ans=0;
    rep(i,0,h) rep(j,0,w) if(dp[i][j]==-1) ans++;
    ll z=power(2,ans);
    cout<<z%mod<<endl;
	return 0;
}