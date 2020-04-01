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
#define MP make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
// #define s second
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
void printl(vector<int> ans){
    cout<<ans.size()<<endl;
    rep(i,0,ans.size()){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    optimizeIO();
    tc{
        int n;
        cin>>n;
        vector<int> v1,v2,v3,v4;
        set<string> se1,se2;
        string s2[n];
        rep(i,0,n){
            string s;
            cin>>s;
            s2[i]=s;
            int n=s.length();
            if(s[0]=='0' && s[n-1]=='0') v1.pb(i);
            else if(s[0]=='0' && s[n-1]=='1') {v2.pb(i);se1.insert(s);}
            else if(s[0]=='1' && s[n-1]=='0') {v3.pb(i);se2.insert(s);}
            else v4.pb(i);
        }
        vector<int> ans;
        if((v2.size())==v3.size()+1 || v3.size()==v2.size()+1){
            printl(ans);
        }
        else if(v2.size()==0 && v3.size()==0){
            cout<<-1<<endl;
        }   
        else {
            int mn=min(v2.size(),v3.size());
            int x=v2.size()-mn,y=v3.size()-mn;
            if(x>0) x-=1;
            else if(y>0) y-=1;
            if(x==0 && y==0){
                printl(ans);
            }
            else if(y>0){
                int exc=y%2?y/2+1:y/2;
                cout<<exc<<endl;
                int i=0,j=0;
                while(j!=exc && i<v3.size()){
                    // cout<<v3[i]+1<<" ";
                    string g=s2[v3[i]];
                    reverse(g.begin(),g.end());
                    if(se1.find(g)!=se1.end()){
                        ans.pb(v3[i]+1);
                        j++;
                    }
                    i++;
                }
                printl(ans);
                cout<<endl;
            }
            else if(x>0){
                int exc=x%2?x/2+1:x/2;
                cout<<exc<<endl;
                int i=0,j=0;
                while(j!=exc && i<v4.size()){
                    // cout<<v3[i]+1<<" ";
                    string g=s2[v4[i]];
                    reverse(g.begin(),g.end());
                    if(se2.find(g)!=se2.end()){
                        ans.pb(v4[i]+1);
                        j++;
                    }
                    i++;
                }
                printl(ans);
                cout<<endl;
            }
        }
    }
}