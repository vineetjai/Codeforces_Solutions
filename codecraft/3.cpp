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
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
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
// using cd = complex<double>;
const double PI = acos(-1);
// void fft(vector<cd> & a, bool invert) {
//     int n = a.size();
//     if (n == 1)
//         return;

//     vector<cd> a0(n / 2), a1(n / 2);
//     for (int i = 0; 2 * i < n; i++) {
//         a0[i] = a[2*i];
//         a1[i] = a[2*i+1];
//     }
//     fft(a0, invert);
//     fft(a1, invert);

//     double ang = 2 * PI / n * (invert ? -1 : 1);
//     cd w(1), wn(cos(ang), sin(ang));
//     for (int i = 0; 2 * i < n; i++) {
//         a[i] = a0[i] + w * a1[i];
//         a[i + n/2] = a0[i] - w * a1[i];
//         if (invert) {
//             a[i] /= 2;
//             a[i + n/2] /= 2;
//         }
//         w *= wn;
//     }
// }
// vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
//     vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
//     int n = 1;
//     while (n < a.size() + b.size()) 
//         n <<= 1;
//     fa.resize(n);
//     fb.resize(n);

//     fft(fa, false);
//     fft(fb, false);
//     for (int i = 0; i < n; i++)
//         fa[i] *= fb[i];
//     fft(fa, true);

//     vector<ll> result(n);
//     for (int i = 0; i < n; i++)
//         result[i] = round(fa[i].real());
//     return result;
// }
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
} 



int main()
{
    fastio();
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    vector<ll> a(n),b(m);
    rep(i,0,n){scanf("%d",&a[i]);a[i]=a[i]%p;}
    rep(i,0,m){scanf("%d",&b[i]);b[i]=b[i]%p;}
    vector<int> c(n+m-2,0);
    int ans=0;
    rep(i,0,n){
        if(a[i]) {ans+=i;break;}
    }
    rep(i,0,m){
        if(b[i]) {ans+=i;break;}
    }
    cout<<ans<<endl;
    // vector<ll> res = multiply(a,b);
    // int ans = -1;
    // rep(i,0,res.size())
    // {
    //     if(res[i]%p!=0)
    //     {
    //         ans = i;
    //         break;
    //     }
    // }
    // printf("%d\n",ans);

}