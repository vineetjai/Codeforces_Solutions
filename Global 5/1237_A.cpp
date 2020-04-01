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
#include <algorithm> //binary_search,sort, next_permutation in lexicographically greater permutation, fill(it1,it2,val)
#include <cmath>
#include <limits.h> //INT_MIN,INT_MAX
#include <numeric>  //iota,partial_sum,inner_product,accumulate(begin,end,num)
#include <functional>  //Arithmetic, comparators, logical
#include <bitset>
#include <unordered_map>
#include <stdio.h> 
#include <cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define pi 3.14159
#define ll long long 
#define ull unsigned long long
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
    ll s=0;
    int cp=0,cn=0;
    rep(i,0,n){
        if(a[i]%2==0) s+=a[i]/2;
        else if(a[i]<0) cn+=1,s+=(a[i])/2;
        else if(a[i]>0) cp+=1,s+=(a[i])/2;
    }
    if(s==0){
        rep(i,0,n) cout<<a[i]/2<<endl;
    }
    else if(s<0){
        rep(i,0,n){
            if(a[i]%2==0 || s==0) cout<<a[i]/2<<endl;
            else if(s!=0 && a[i]>0){s+=1;cout<<a[i]/2+1<<endl;}
            else cout<<a[i]/2<<endl;
        }
    }
    else{
        rep(i,0,n){
            if(a[i]%2==0 || s==0) cout<<a[i]/2<<endl;
            else if(s!=0 && a[i]<0){s-=1;cout<<a[i]/2-1<<endl;}
            else cout<<a[i]/2<<endl;
        }
    }
	return 0;
}