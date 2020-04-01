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
    tc{
        int n;
        cin>>n;
        string s[2];
        map<int,int> m,m1;
        m1[1]=1,m1[2]=1,m[3]=1,m[4]=1,m[5]=1,m[6]=1;
        cin>>s[0]>>s[1];
        int c=0;
        bool flag=true,ans_flag=true;
        rep(i,0,n){
            if(m.find(s[0][i]-'0')!=m.end() && m.find(s[1][i]-'0')!=m.end()){c++; flag=!flag;}
            else if( (m.find(s[0][i]-'0')!=m.end() && m1.find(s[1][i]-'0')!=m1.end()) && flag){
                ans_flag=false;break;
            }
            else if((m1.find(s[0][i]-'0')!=m1.end() && m.find(s[1][i]-'0')!=m.end()) && !flag){
                ans_flag=false;break;
            }
        }
        // cout<<c<<endl;
        string s1= c%2==1 && ans_flag?"YES":"NO";
        cout<<s1<<endl;
    }
	return 0;
}