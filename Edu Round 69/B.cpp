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
bool solve(int x,int n,int a[]){
    for(int i=x;i<n-1;i++){
        if(a[i]<a[i+1]) return false;
    }
    return true;
}
bool solve1(int x,int n,int a[]){
    for(int i=x;i<n-1;i++){
        if(a[i]>a[i+1]) return false;
    }
    return true;
}
int main(){
	optimizeIO();
    
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n) cin>>a[i];
    int num=*max_element(a,a+n),idx;
    rep(i,0,n) if(a[i]==num) idx=i;
    // cout<<idx<<endl;
    // cout<<solve(idx,n,a)<<" "<<solve1(0,idx,a)<<endl;
    if(solve(idx,n,a) && solve1(0,idx,a)) cout<<"YES\n";
    else cout<<"NO\n";
	return 0;
}