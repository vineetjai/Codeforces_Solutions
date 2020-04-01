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
int main(){
	optimizeIO();
    int t;
    cin>>t;
    while(t--){
        LL n;
        long long ans,i;
        cin>>n;
        LL a[n];
        for( i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        if(n>1){
            ans=a[0]*a[n-1];
        }
        else{
            ans=a[0]*a[0];
        }
        LL flag=0;
        LL id=0;
        vector<LL> v; 
        for ( i=2; i<=sqrt(ans); i++) 
            if (ans%i==0){
                    if(ans!=i*i) v.push_back(i);
                    v.push_back(ans/i); 
                }
        sort(v.begin(),v.end());
        // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        // cout<<endl;
        if(v.size()!=n) flag=1;
        else{
            for(int i=0;i<v.size();i++){
                if(v[i]!=a[i]) {flag=1;break;}
            }
        }
        if(flag){cout<<-1<<endl;}
        if(flag==0) cout<<ans<<endl;
    }
	return 0;
}