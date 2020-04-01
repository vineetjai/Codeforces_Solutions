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
#define pb push_back
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
vector<int> solve(std::vector<int> v1,std::vector<int> v2){
    int st=0,st1=0;
    vector<int> v3;
    while(1){
        if(st>=v1.size() || st1>=v2.size()) break;
        vector<int>::iterator low;
        low=lower_bound(v2.begin()+st1,v2.end(),v1[st]);
        if(low==v2.end())break;
        else{
            int idx=low-v2.begin();
            if(idx<0 && idx>v2.size()) break;
            v3.push_back(v2[idx]);
            st1=idx+1;
            st++;
        }
    }
    return v3;
}
int main(){
    optimizeIO();
    vector <vector<int > >v(6);
    int n,x,j;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        if(x==4)j=0;
        else if(x==8) j=1;
        else if(x==15)j=2;
        else if(x==16)j=3;
        else if(x==23)j=4;
        else j=5;
        if(v[j].size()==0){
                vector<int> v1;
                v1.pb(i+1);
                v[j]=v1;
        }
        else v[j].pb(i+1);
    }

    vector<int> v1=v[0];
    for(int i=1;i<6;i++){
        vector<int> v2=v[i];
        if(v1.size()==0)  break;
        v1=solve(v1,v2);
    }

    cout<<n-6*v1.size()<<endl;
    return 0;
}