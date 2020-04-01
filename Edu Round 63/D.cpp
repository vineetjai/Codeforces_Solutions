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

ll maxSubArraySum1(ll a[], int size) 
{ 
    ll max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 
ll maxSubArraySum(ll a[], int size,int x) { 
    ll max_so_far = INT_MIN, max_ending_here = 0,start =0, end = 0, s=0; 
    for (int i=0; i< size; i++ ) { 
        max_ending_here += a[i]; 
        if (max_so_far < max_ending_here){ 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        }
        if (max_ending_here < 0) { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    }  
    for(int i=start;i<=end;i++){
    	a[i]=x*a[i];
    }
    return maxSubArraySum1(a,size);
} 

ll smallestSumSubarr(ll a[], int size,int x) {
    ll max_so_far = INT_MAX, max_ending_here = 0,start =0, end = 0, s=0; 
    for (int i=0; i< size; i++ ) { 
        max_ending_here += a[i]; 
        if (max_so_far > max_ending_here){ 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        }
        if (max_ending_here > 0) { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    }  
    for(int i=start;i<=end;i++){
    	a[i]=x*a[i];
    }
    return maxSubArraySum1(a,size);
} 
int main(){
	int n,x;
	cin>>n>>x;
	// cout<<x<<endl;
	ll a[n],b[n],max3,max1,max2,s=0;
	REP(i,0,n) {cin>>a[i];b[i]=a[i];}
	max2=maxSubArraySum1(a,n);
	if(x<0){
		max1=max(smallestSumSubarr(a,n,x),s);
	}
	else max3=max(maxSubArraySum(b,n,x),s);
	cout<<max(max(max3,max1),max2)<<endl;
}