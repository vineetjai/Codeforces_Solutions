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
#include <string>
#include <sstream>
#include <iostream>
// #include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
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
const long long LL_INF = (long long) 2e18 + 5;

int N, K;
vector<int> A;
vector<long long> prefix_sum, suffix_sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    prefix_sum.assign(N + 1, 0);
    suffix_sum.assign(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_sum[i + 1] = prefix_sum[i] + A[i];

    for (int i = N - 1; i >= 0; i--)
        suffix_sum[i] = suffix_sum[i + 1] + A[i];

    long long answer = LL_INF;

    for (int i = 0, j = 0; i < N; i = j) {
        long long value = A[i];

        while (j < N && A[j] == value)
            j++;

        if (j - i >= K) {
            answer = 0;
            break;
        }

        int need = K - (j - i);
        int before = i;
        int after = N - j;
        long long before_cost = before * value - prefix_sum[i];
        long long after_cost = suffix_sum[j] - after * value;

        if (before >= need)
            answer = min(answer, before_cost - (before - need));

        if (after >= need)
            answer = min(answer, after_cost - (after - need));

        answer = min(answer, before_cost + after_cost - (before + after - need));
    }

    cout << answer << '\n';
}
