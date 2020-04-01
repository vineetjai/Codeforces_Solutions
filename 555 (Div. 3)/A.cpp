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
	string n;
	cin>>n;
	LL k=0;
	set<string >gh;
	
	k++;
	gh.insert(n);
	while(n.length()!=1){
		n=to_string(stoll(n)+1);
		int x=n.length()-1;
		while(n[n.length()-1]=='0'){
			// gh.insert(n);
			n.pop_back();
		}
		gh.insert(n);
		k++;
	}
	// for (auto i:gh){
	// 	cout<<i<<endl;
	// }
	cout<<gh.size()+8<<endl;
}