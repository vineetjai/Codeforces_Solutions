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

#include <algorithm> //binary_search,sort
#include <cmath>
#include <limits.h> //INT_MIN,INT_MAX

#include <numeric>  //iota,partial_sum,inner_product,accumulate(begin,end,num)
#include <functional>  //Arithmetic, comparators, logical


#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,b,a) for(int i=b-1;i>=a;i--)
#define FORE(a) for(auto ele : a )
#define ALL(a) begin(a), end(a)
#define SET(a,b) memset(a,b,sizeof(a))

#define ll long long 
#define PB push_back
#define PF push_front //deque
#define MP make_pair
#define PQ priority_queue
#define MOD 1000000007
#define F first
#define S second
#define PII pair< int, int >
#define TC int t; cin >> t; while(t--)

using namespace std;

void optimizeIO(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
}
ll gcd(ll a, ll b) { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 
int main(){
	optimizeIO();
	ll n,m,gc,ans,gc1,ind;
	cin>>n>>m;
	ans=abs(n-m);
	// ll c=min(n,m),d=max(n,m);
	// if(d%c==0){
	// 	cout<<0<<endl;
	// }
	// else if(gcd(n,m)==1){
	// 	cout<<(c/ans+1)*ans-c<<endl;
	// }
	// else{
	// 	c=max(c,d);
	// 	cout<<(ceil((ll)(double(c)/ans)))*ans-c<<endl;
	// 	// else cout<<(c/ans+1)*ans-c<<endl;
	// }
}