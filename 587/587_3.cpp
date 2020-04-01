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
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    int x5,y5,x6,y6;

    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    cin>>x5>>y5>>x6>>y6;

    rep(i,x1,x2){
        if(i<=x4 && i>=x3){
            if(i<=x6 && i>=x5){
                // if((y5>y4+1 && ( || ) ) || (y3>y6+1 && ( || ) ) ){
                //     cout<<"YES\n";
                //     return 0;
                // }
                pair<int,int> pi1=mp(y3,y4),pi2=mp(y5,y6),pi=mp(-1,-1);
                if(y6>y4){
                    swap(pi1,pi2);
                }
                int flag=0;

                if(pi1.first<=pi2.second){
                    flag=1;
                    pi=mp(min(pi2.first,pi1.first),pi1.second);
                }

                if((y1+1<pi.first || y2>pi.second+1)){
                    cout<<"YES\n";
                    return 0;
                }
                if(flag==1){
                    if((pi1.second<=y3 && ((pi1.second >y2+1 && y2>pi2.first+1) || (y2<=pi2.second) )) || ((pi1.second > y3 && y3>pi2.first) || (pi1.second==y3 && y3!=y2 && pi1.second>pi2.first+1))){
                        cout<<"YES\n";
                        return 0;
                    }
                }
            }
            else{
                if(y1+1<y3 || y2>y4+1){
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
        else if(i<=x6 && i>=x5){
            if(y1+1<y5 || y2>y6+1){
                    cout<<"YES\n";
                    return 0;
            }
        }
        else {
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
	return 0;
}