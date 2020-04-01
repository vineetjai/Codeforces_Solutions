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

#define LL long long 
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
	LL n,m;
	cin>>n>>m;
	LL a[n],b[m],a_odd=0,b_odd=0;
	REP(i,0,n){
		cin>>a[i];
		if(a[i]%2==1){
			a_odd+=1;
		}
	}
	REP(i,0,m){
		cin>>b[i];
		if(b[i]%2==1){
			b_odd+=1;
		}
	}
	LL s=0;
	s+= min(a_odd,m-b_odd);
	s+=min(b_odd,n- a_odd);
	cout<<s<<endl;	
}