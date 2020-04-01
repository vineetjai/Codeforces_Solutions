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
int op(int l,int x,int k){
    if(l<x){
        return x-l;
    }
    else {
        return 7-l+x;
    }
}
int main(){
	optimizeIO();
    int n,m;
    cin>>n>>m;
    int a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int max_=0;
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1]){
            int l=a[i];
            a[i]=min(a[i+1],a[i-1]);
            int y=op(l,a[i],m);
            
            max_=max(max_,);
        }
    }
    cout<<max_<<endl;
	return 0;
}