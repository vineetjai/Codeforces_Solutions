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
// g1=s.substr(0,n/2);
// g2=s.substr(n/2+n%2,n/2);
#include <cctype> //isaplha
#include <iomanip>      // std::setprecision
#include <algorithm> //binary_search,sort, next_permutation in lexicographically greater permutation
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
    int t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll a[n],b[n],max_cut=0,max_pos=-1,val=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
            max_cut=max(max_cut,a[i]);
            if(a[i]-b[i]>0  && a[i]-b[i]>val){
                val=a[i]-b[i];
                max_pos=i;
            }
        }
        if(max_pos==-1 && (max_cut>=x)) cout<<1<<endl;
        else if(max_pos==-1 && (max_cut<x)) cout<<-1<<endl;
        else{
            ll cut=a[max_pos],non_cut=b[max_pos];
            x-=max_cut;
            ll ans=1;
            if(x<=0) cout<<ans<<endl;
            else {
                ans+=ceil(double(x)/double(cut - non_cut));
                cout<<ans<<endl;
            }
        }
    }
	return 0;
}