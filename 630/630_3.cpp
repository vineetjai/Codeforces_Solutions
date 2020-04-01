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
#include <unordered_set>
#include <stdio.h> 
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
// #include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
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
int gcd(int a, int b){ 
    if (a == 0)  return b; 
    return gcd(b % a, a); 
} 
int main(){
    optimizeIO();
	tc{
    	int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<map<char,int>> v(k);
        rep(i,0,k){
            map<char,int> x;
            for(int j=i;j<n;j+=k){
                x[s[j]]++;
            }
            v[i]=x;
        }
        int ans=0;
        if(k%2){
            ans=INT_MAX;
            map<char,int> m=v[k/2];
            for(auto i:m) ans=min(ans,n/k-i.second);
        }
        int up= k/2-1;
        rep(i,0,up+1){
            int mx=INT_MIN;
            map<char,int> m1=v[i],m2=v[k-1-i];
            for(auto j:m2){
                m1[j.first]+=j.second;
            }
            
            for(auto j:m1) mx=max(mx,j.second);
            ans= ans+2*(n/k)-mx;
        }
        cout<<ans<<endl;
    }
}