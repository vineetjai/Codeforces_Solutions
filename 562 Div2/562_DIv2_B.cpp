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
bool check(vector<pair<int,int> > s,int it,int x,int y){
    while(it<s.size()){
        if(s[it].first==y || s[it].second==y){
            it++; 
            continue;
        }
        else if(s[it].first!=x && s[it].second!=x) return false;
        it++;
    }
    return true;
}
int main(){
	optimizeIO();
    int n,m,x,y;
    cin>>n>>m;
    vector<pair<int,int> > s;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        s.push_back(make_pair(x,y));
    }
    if(s.size()==1){
        cout<<"YES\n";
        return 0;
    }
    else{
        int it=0;
        int it1=0;
        int x=s[it].first,y=s[it].second;

        while((s[it].first==x || s[it].second ==x) && it<m){
            it++;
        }
        while((s[it1].first==y || s[it1].second ==y) && it1<m){
            it1++;
        }


        if(it>=m-1){
            cout<<"YES\n";
            return 0;
        }
        else{
            int l1=s[it].first,l2=s[it].second;
            int it2=it;
            if(check(s,it,l1,x)){
                 cout<<"YES\n";
            return 0;
            }
            else if(check(s,it2,l2,x)){
                cout<<"YES\n";
            return 0;
            }
        }


        if(it1>=m-1){
            cout<<"YES\n";
            return 0;
        }
        else{
            int l1=s[it1].first,l2=s[it1].second;
            int it2=it1;
            if(check(s,it1,l1,y)){
                cout<<"YES\n";
                return 0;
            }
            else if(check(s,it2,l2,y)){
                cout<<"YES\n";
                return 0;
            }
        }

    }
    cout<<"NO\n";
	return 0;
}