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
#define mod 998244353
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
bool isPrime(int n) { 

    if (n <= 1) 
        return false;
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
int main(){
	optimizeIO();
	int n;
    cin>>n;
    int flag=0;
    for(int i=0;i<3*n-1;i++){
        if((3*n-i)%2==0){
            int z=(3*n-i)/2;
            if(isPrime(z) && z>=n){

                flag=1;
                int y=z-n;
                cout<<y+n<<endl;
                for(int i=1;i<n;i++){
                    cout<<i<<" "<<i+1<<endl;
                }
                cout<<1<<" "<<n<<endl;
                int c=0,idx=1;
                while(c<y){
                    cout<<idx<<" "<<idx+2<<endl;
                    idx=idx+1;
                    c++;
                    if(c<y){
                        cout<<idx<<" "<<idx+2<<endl;
                        idx+=3;
                        c+=1;
                    }

                }
            }
        }
        if(flag) break;

    }
    if(!flag) cout<<-1<<endl;
}