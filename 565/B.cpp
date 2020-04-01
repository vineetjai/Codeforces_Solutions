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
        int n;
        cin>>n;
        ll a[n],c=0,c1=0,c2=0,ans=0;
        for(int i=0;i<n;i++) {cin>>a[i]; a[i]=a[i]%3;}
        for(int i=0;i<n;i++){
            if(a[i]==0) c++;
            else if(a[i]==1) c1++;
            else if(a[i]==2) c2++;
        }
        ans=c;
        if(c1>c2){
            ans +=c2;
            c1=c1-c2;
            ans+= (c1)/3;
        }
        else if(c2>=c1){
            ans +=c1;
            c2=c2-c1;
            ans+= c2/3;
        }
        cout<<ans<<endl;
    }
	return 0;
}