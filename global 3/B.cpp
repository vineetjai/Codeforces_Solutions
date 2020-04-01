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

ll solve(ll x,ll b[],ll s_st,ll m){
    ll j;
    for(j=s_st;j<m;j++){
        if(x<b[j]) return j;
    }
    return -1;
}
ll solve1(ll a[],ll x,ll f_st,ll n){
    ll i;
    for(i=f_st;i<n;i++){
        if(a[i]>x) return i;
    }
    return -1;
}
void optimizeIO(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
	optimizeIO();
    ll i,n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    ll a[n],b[m],d[m];
    for(i=0;i<n;i++) {cin>>a[i]; a[i]=a[i]+ta;}
    for(i=0;i<m;i++) {cin>>b[i]; d[i]=d[i]+tb;}

    ll f_st=0,s_st=0;
    while(f_st<n && s_st<m && k>0){
        ll x=solve(a[f_st+1],b,s_st,m)-s_st;
        ll y=solve1(a,b[s_st+1],f_st,n)-f_st;
        if(x==-1 || y==-1){
            cout<<-1<<endl;
            return 0;
        }
        if(x>y){
            s_st+=x;
            k--;
            f_st++;
        }
        else if(x<y){
            f_st+=y;
            k--;
            s_st++;
        }
        else{
            f_st++;
            s_st++;
            k--;
        }
        cout<<f_st<<" "<<s_st<<endl;
    }
    
    if(k>0 || (f_st==n-1 || s_st==m-1)){
        cout<<-1<<endl;
    }
    else{
        ll f=a[f_st+1];
        ll z=solve(f,b,s_st,m);
        if(z==-1) cout<<d[m-1]<<endl;
        else cout<<min(d[z],d[s_st])<<endl;
    }
	return 0;
}