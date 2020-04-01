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
bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
   return a.second<b.second;
}

int main(){
    optimizeIO();
    tc{
        int n;
        cin>>n;
        int arr[n];
        map<int,int> ev;
        rep(i,0,n){
            cin>>arr[i];
            if(arr[i]%2==0) ev[arr[i]]++;
        }
        ll ans=0;
       
        while(ev.size()>0){
            map<int,int> :: reverse_iterator it=ev.rbegin();
            // cout<<it->first<<"-----"<<it->second<<endl;
            int z=(it->first)/2,t=it->second;
            ev.erase(it->first);
            if(z%2==0){
                ev[z]+=t;
            }
            ans++;
            // for(auto j:ev){
            // cout<<j.f<<" "<<j.s<<endl;
        // }
            // cout<<z<<endl;
        }
        cout<<ans<<endl;
    }
}