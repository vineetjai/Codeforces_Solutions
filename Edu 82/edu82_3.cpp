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
const ll mod=1e9+7;
#define f first
#define s second
#define pii pair< int, int >
#define tc int t; cin >> t; while(t--)
using namespace std;

void optimizeIO(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
}  

string getString(char x) {
    string s(1, x); 
    return s;    
} 
int main(){
    optimizeIO();
    tc{
        string s;
        cin>>s;
        int n=s.length();
        if(n==1){
            cout<<"YES\n";
            cout<<"abcdefghijklmnopqrstuvwxyz\n";
            continue;
        }
        map<char,set<char> > m; 
        rep(i,1,n-1){
            m[s[i]].insert(s[i-1]);
            m[s[i]].insert(s[i+1]);
        }
        m[s[0]].insert(s[1]);
        m[s[n-1]].insert(s[n-2]);

        char cha='-';
        int c=0,flag=0;
        rep(i,0,26){
            if(m.find('a'+i)!=m.end() && m['a'+i].size()==1){
                if(cha=='-'){cha='a'+i;c++;}
                c++; 
            }
            if(m.find('a'+i)!=m.end() && m['a'+i].size()>=3) {flag=1; break;}
        } 
        if( flag || (c==0)){
            cout<<"NO\n";
            continue;
        }
        string g="";
        set<char> s1;
        g+=getString(cha);
        s1.insert(cha);
        char x=' ';
        while(s1.size()!=26 && m.size()>0){
            if(x==cha) break;
            x=cha;
            int flag=0;
            set<char> s2=m[x];
            m.erase(x);
            for(auto j:s2){
                if(s1.find(j)==s1.end() && flag==0){
                    g+=getString(j);
                    s1.insert(j);
                    cha=j;
                    flag=1;
                }
                else if(s1.find(j)==s1.end() && flag==1){
                    flag=2;
                    break;
                }
            }
            if(flag==2){
                cout<<"NO\n";
                break;
            }
        }
        set<char> full;
        rep(i,0,26) if(s1.find('a'+i)==s1.end()) full.insert('a'+i);
        for(auto j:full) g+=j;
        cout<<"YES\n";
        cout<<g<<endl;
    }   
}