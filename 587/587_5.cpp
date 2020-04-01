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
int search(int n, ll x){
    vector<int> v(n+1);

    for(int i=1;i<=n;i++){
        v[i]=to_string(i).length();
    }
    for(int i=1;i<=n;i++){
        if(x-v[i]>0){
            x-=v[i];
        }
        else if(x-v[i]==0){
            string l=to_string(i);
            return l[l.length()-1]-'0';
        }
        else{
            string g=to_string(i);
            return (g[x-1]-'0');
        }
    }
}
int main(){
	optimizeIO();
    vector<long long > v(100001);
    v[0]=0;
    for(int i=1;i<100001;i++){
        v[i]=v[i-1]+to_string(i).length();
    }
    tc{
        ll x;
        cin>>x;
        // double y=2*x+1/4.0;
        // y=sqrt(y);
        // y-=0.5;
        // double lower= y-1.0;
        // ll ans=lower;
        // while(!(ans<=y && ans>=lower)){
        //     ans++;
        // }
        // cout<<ans<<endl;
        ll ans=0,i=1,last=0,sum=0;
        while(1){
            if(sum+v[i]<x){
                x-=(sum+v[i]);
                sum=sum+v[i];
            }
            else if(sum+v[i]==x){
                string l=to_string(i);
                // ans= l[l.length()-1]-'0';
                ans=search(i,x);
                break;
            }
            else{
                ans=search(i,x);
                break;
            }
            i++;
        }
        cout<<ans<<endl;
    }
	return 0;
}