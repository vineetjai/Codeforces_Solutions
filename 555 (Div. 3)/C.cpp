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


#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,b,a) for(int i=b-1;i>=a;i--)
#define FORE(a) for(auto ele : a )
#define ALL(a) begin(a), end(a)
#define SET(a,b) memset(a,b,sizeof(a))

#define ll long long 
#define PB push_back
#define PF push_front //deque
#define MP make_pair
#define PQ priority_queue
#define MOD 1000000007
#define F first
#define S second
#define PII pair< int, int >
#define TC int t; cin >> t; while(t--)

using namespace std;

void optimizeIO(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
}
ll gcd(ll a, ll b) { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 

string solve(int en,int st, int a[],int last,string h,int ans){
	string g=h;
	while(en>=st){
		// cout<<st<<en<<endl;
		if(last>a[st] && last > a[en]) break;
		if(a[st]>a[en]){
			if(last < a[en]){last=a[en]; ans++; g+="R"; en--;}
			else if(a[st]>last) {
				last=a[st];
				ans++; g+="L";
				st++;
			}
			else break;
		}
		else if(a[st]<a[en]){
			if(last < a[st]){last=a[st];ans++; g+="L"; st++;}
			else  if(a[en]>last){
				last=a[en];
				ans++; g+="R";
				en--;
			}
			else break;
		}
		else if(st==en){
			if(a[st]>last){last=a[st];
			g+="R";}
			break;
		}
		else if(a[st]==a[en] && a[st]>last){
			string h=solve(en,st+1,a,a[st],"L",ans);
			string rt=solve(en-1,st,a,a[en],"R",ans);
			g+=(rt.length()>=h.length()? rt:h) ;
			return g;
		}
		else break;
	}
	return g;
}
int main(){
	optimizeIO();
	int n,x;
	cin>>n;
	int a[n]; 
	for(int i=0;i<n;i++) cin>>a[i];
	int l=0,last=INT_MIN,st=0,en=n-1;
	int ans=0;
	string g="";
	g=solve(en,st,a,last,g,ans);
	cout<<g.length()<<endl<<g<<endl;
}