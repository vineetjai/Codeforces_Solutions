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

char p[1010000];
int n;
long long A[1010000], B[1010000], res;
int main() {
	int i;
	scanf("%s", p+1);
	for (i = 1; p[i]; i++);
	n = i - 1;
	int c = 0;
	for (i = 1; i <= n; i++) {
		if (p[i] == 'v' && p[i - 1] == 'v')c++;
		A[i] = c;
	}
	c = 0;
	for (i = n; i >= 1; i--) {
		if (p[i] == 'v' && p[i + 1] == 'v')c++;
		B[i] = c;
	}
	for (i = 1; i <= n; i++) {
		if (p[i] == 'o')res += A[i - 1] * B[i + 1];
	}
	printf("%lld\n", res);
}