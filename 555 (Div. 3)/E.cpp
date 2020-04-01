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
int main(){
	optimizeIO();
	int n;
	cin>>n;
	int a[n],b[n],x;
	map<int,int> m;
	int max_;
	for(int i=0;i<n;i++){ cin>>a[i];}
	// for(int i=0;i<n;i++) {cin>>b[i]; m[b[i]]++;}
	// int c[n];
	// // cout<<max_<<endl;
	// for(int i=0;i<n;i++){
	// 	int x=(n-a[i]);
	// 	// cout<<m.rbegin()->first<<endl;
	// 	max_=m.rbegin()->first;
	// 	if(m.rbegin()->first >= x){
	// 		while(1){
	// 			if(x>max_ || m.find(x)!=m.end()) break;
	// 			x++;
	// 			// cout<<x<<endl;
	// 		}
	// 		if(m.find(x)!=m.end() ){
	// 			c[i]=(a[i]+x)%n;
	// 			if(m[x]>1)m[x]--;
	// 			else m.erase(x);
	// 		}
	// 		else{
	// 			x=m.begin()->first;
	// 			c[i]=(a[i]+x)%n;
	// 			if(m[x]>1)m[x]--;
	// 			else m.erase(x);
	// 		}
	// 	}
	// 	else{
	// 		c[i]=(a[i]+m.begin()->first)%n;
	// 		if(m.begin()->second<=1) m.erase(m.begin());
	// 	}
	// }
	// for(int i=0;i<n;i++){
	// 	cout<<c[i]<<" ";
	// }
	multiset<int> s;
	for(int i=0;i<n;i++){
		cin>>x;
		s.insert(x);
	}
	for(int i=0;i<n;i++){
		int t=(n-a[i])%n;
		auto it=s.lower_bound(t);
		if(it==s.end()) it=s.begin();
		cout<<((a[i]+(*it))%n)<<" ";
        s.erase(it);
	}
	cout<<endl;
}