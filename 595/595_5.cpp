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
string covert(ll x){
    if(x==0) return "0";
    string g="";
    while(x>0){
        if(x%3==1) g+="1";
        else if(x%3==2) g+="2";
        else g+="0";
        x/=3;
    }
    reverse(g.begin(),g.end());
    return g;
}
bool check(string s){
    rep(i,0,s.length()) if(s[i]=='2') return false;
    return true;
}
ull binaryToDecimal(string n) { 
    string num = n; 
    ull dec_value = 0; 
    ull base = 1; 
    ll len = num.length(); 
    for (ll i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        else if(num[i]=='2') dec_value+=base*2;
        base = base * 3; 
    } 
  
    return dec_value; 
}

void optimizeIO(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
}
string convert(string g){
    string l=g;
    int n=l.length();
    int idx=-1,flag=0;
    rep(i,0,n){
        if(l[i]=='0') idx=i;
        else if(l[i]=='2' && idx==-1) return "1"+repeat("0",n);
        else if(l[i]=='2' && idx!=-1) break;
    }
    if(idx!=-1) l[idx]='1';
    if(idx!=-1)rep(i,idx+1,n) l[i]='0';
    return l;
}
int main(){
	optimizeIO();
    tc{
        ll n;
        cin>>n;
        string g= covert(n);
        if(check(g)) {cout<<n<<endl;continue;}
        string ans=convert(g);
        ull x=binaryToDecimal(ans);
        cout<<x<<endl;

    }
	return 0;
}