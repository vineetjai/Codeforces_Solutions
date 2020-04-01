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
	int n;
	cin>>n;
	int a[n];
	rep(i,0,n) cin>>a[i];
	int fi=a[0],gre=a[0];
	int s=a[0],sum=a[0];
	vector<int> v;
	v.pb(1);
	for(int i=1;i<n;i++){
		if(2*a[i]<=gre) {s+=a[i];v.pb(i+1);}
		sum+=a[i];
	}

	if(sum<2*s){
		cout<<v.size()<<endl;
		rep(i,0,v.size()) cout<<v[i]<<" ";
		cout<<endl;
	}
	else cout<<0<<endl;
	return 0;
}