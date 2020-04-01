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
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        vector<vector<int> >v(n);
        map<pair<int,int> ,int> m;
        int x_min=-1e5,x_max=1e5,y_min=-1e5,y_max=1e5;
        for(int i=0;i<n;i++){
            vector<int> v1(6);
            rep(i,0,6) cin>>v1[i];
            v.pb(v1);
            if(v1[2]==0){
                x_min=max(x_min,v1[0]);
            }
            if(v1[3]==0){
                y_max=min(y_max,v1[1]);
            }
            if(v1[4]==0) x_max=min(x_max,v1[0]);
            if(v1[5]==0) y_min=max(y_min,v1[1]);
        }
        // cout<<x_min<<" "<<x_max<<" "<<y_min<<" "<<y_max<<endl;
        if(x_max<x_min || y_min>y_max){
            cout<<0<<endl;
        }
        else{
            cout<<1<<" "<<x_min<<" "<<y_min<<endl;
        }
    }
	return 0;
}