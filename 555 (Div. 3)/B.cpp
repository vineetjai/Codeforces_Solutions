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

#define LL long long 
#define PB push_back
#define PF push_front //deque
#define MP make_pair
#define PQ priority_queue
#define MOD 1000000007
#define F first
#define S second
#define PII pair< int, int >
#define TC int t; cin >> t; while(t--)
#include <type_traits>
#include <bitset>
using namespace std;

void optimizeIO(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
}

string decToBinary(LL n) { 
    LL binaryNum[32],i = 0; 
    while (n > 0) { 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    string s="";
    for (LL j = i - 1; j >= 0; j--) 
        s+=to_string(binaryNum[j]); 
    return s;
} 
int check(string s){
	int flag=0,ans;
	int flag1=0;
	for(int i=0;i<s.length();i++)
		if(s[i]=='0') flag1=1;
	if(!flag1) return -1;
	for(int i=0;i<s.length();i++)
		 if(s[i]=='1' ) return i;
	return -1;
}
int main(){
	optimizeIO();
	int l;
	string s;
	char x;
	map<char,int> m;
	cin>>l>>s;
	for(int i=1;i<=9;i++){
		cin>>x;
		m['0'+i]=x;
	}
	int flag=0;
	for(int i=0;i<s.length();i++){
		if(flag==1 && s[i]>m[s[i]]) break;
		else if(flag==0 && s[i]==m[s[i]]) continue;
		else if(s[i]< m[s[i]]){
			s[i]=m[s[i]];
			flag=1;
		}
	}
	cout<<s<<endl;
}