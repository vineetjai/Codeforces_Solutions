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
    if(n<=0) return "";
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
        string s;
        cin>>s;
        int a[4]={0,0,0,0};
        rep(i,0,s.length()){
            if(s[i]=='U') a[0]++;
            else if(s[i]=='D') a[1]++;
            else if(s[i]=='L') a[2]++;
            else if(s[i]=='R') a[3]++;
        }

        a[2]=min(a[2],a[3]);
        a[3]=min(a[2],a[3]);
        a[1]=min(a[1],a[0]);
        a[0]=min(a[0],a[1]);
        // cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
        string g=repeat("U",min(a[0],1)), h=repeat("R",min(a[3],1)),f=repeat("D",a[1]),k=repeat("L",a[2]),l=repeat("U",a[0]-1),m=repeat("R",a[3]-1);
        string ls=g+h+f+k+l+m;
        if(h=="") ls=repeat("U",min(a[0],1))+repeat("D",min(a[0],1));
        if(g=="") ls=repeat("R",min(a[2],1))+repeat("L",min(a[2],1));
        cout<<ls.length()<<endl;
        cout<<ls<<endl;
    }
}