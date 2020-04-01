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
    string s;
    cin >> s;
    vector<set<int> > poss(26);
    for (int i = 0; i < int(s.size()); ++i) {
        poss[s[i] - 'a'].insert(i);
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            --pos;
            poss[s[pos] - 'a'].erase(pos);
            s[pos] = c;
            poss[s[pos] - 'a'].insert(pos);
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            int cnt = 0;
            for (int c = 0; c < 26; ++c) {
                auto it = poss[c].lower_bound(l);
                if (it != poss[c].end() && *it <= r) ++cnt;
            }
            cout << cnt << endl;
        }
    }
    
    return 0;
	return 0;
}