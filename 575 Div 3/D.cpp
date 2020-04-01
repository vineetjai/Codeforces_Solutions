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
    int q;
    cin>>q;
    while(q--){
        int n,k,min_=INT_MAX;
        cin>>n>>k;
        string s;
        cin>>s;
        for(int l=0;l<3;l++){

            char y[3]={'R','G','B'};
            int dp1[n],idx=l;

            if(s[0]!=y[idx] ) dp1[0]=1;
            else if(s[0]==y[idx]) dp1[0]=0;

            for(int i=1;i<n;i++){
                idx=(idx+1)%3;
                if(s[i]!=y[idx] ) dp1[i]=1+dp1[i-1];
                else dp1[i]=dp1[i-1];         
            }

            min_=min(min_,dp1[k-1]);
            for(int i=k;i<n-1;i++) min_ =min(min_,dp1[i]-dp1[i-k]);
            if(n==k) min_ = min(min_,dp1[n-1]);
            else min_ =min(min_,dp1[n-1]-dp1[n-1-k]);
        }
        cout<<min_<<endl;
    }
	return 0;
}

// Solution for easy constraint version

// int main(){
//     optimizeIO();
//     int q;
//     cin>>q;
//     while(q--){
//         int n,k;
//         cin>>n>>k;
//         string s;
//         cin>>s;
//         int min_=k-1;
//         for(int i=0;i<n-k+1;i++){
//             int idx,c=0;
//             char y[3]={'R','G','B'};
//             idx=0;
//             for(int j=i;j<i+k;j++){
//                 if(s[j]!=y[idx]) c+=1;
//                 idx=(idx+1)%3;
//             }
//             min_=min(min_,c);

//             c=0,idx=1;
//             for(int j=i;j<i+k;j++){
//                 if(s[j]!=y[idx]) c+=1;
//                 idx=(idx+1)%3;
//             }
//             min_=min(min_,c);

//             c=0,idx=2;
//             for(int j=i;j<i+k;j++){
//                 if(s[j]!=y[idx]) c+=1;
//                 idx=(idx+1)%3;
//             }
//             min_=min(min_,c);
//         }
//         cout<<min_<<endl;
//     }
//     return 0;
// }