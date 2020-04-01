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
    int n,m,k;
    cin>>n>>m;
    int b[n+1],id=1;
    for(int i=1;i<=n;i++) b[i]=-1;
    for(int i=1;i<=m;i++){
        cin>>k;
        int a[k+1];
        int x=-1;
        for(int i=1;i<=k;i++) {cin>>a[i]; if(b[a[i]]!=-1) x=b[a[i]];}
        if(x==-1){
            for(int i=1;i<=k;i++){
                b[a[i]]=id;
            }
            id++;
        }
        else{
            for(int i=1;i<=k;i++){
                b[a[i]]=x;
            }
        }
    }
    int v[id];
    for(int i=0;i<id;i++) v[i]=0;
    for(int i=1;i<=n;i++){
        v[b[i]]++;
    }
    for(int i=1;i<=n;i++){
        cout<<v[b[i]]<<" ";
    }
    cout<<endl;
	return 0;
}