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
#define ll long long int
#define li long int
#define ull unsigned long long int
#define pb(k) push_back(k)
#define rep(i,n) for(int i =0;i<n;i++)
#define repk(i,k,n) for(int i =k; i<n; i++)
#define rrep(i,n) for(int i = n-1;i>=0;i--)
#define rrepk(i,n,k) for(int i = n-1; i>=k; i--)
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define tc int t;cin>>t;while(t--)
using namespace std;

void bit(ull a,vector<int> &arr)
{
    while(a>0)
    {
        arr.pb(a%2);
        a/=2;
    }
    reverse(arr.begin(),arr.end());
}
ull power(ull a,int b)
{
    ull res = 1;
    while(b>0)
    {
        if(b&1)res*=a;
        b = b>>1;
        a*=a;
    }
    return res;
}
vi a(1000001,0);
int n;
int main()
{
    tc{
        int n;
        cin>>n;
        unordered_map<int,int> mp;
        vi ans(n+1,0);
        vi vis(n+1,0);
        rep(i,n)
        {
            int x;
            cin>>x;
            mp[i+1] = x;
        }
        int c = 1;
        unordered_map<int,int> hash;
        for(int i = 1; i<=n; i++)
        {
            if(vis[i] == 0)
            {
                int count = 1;
                int t = mp[i];
                vis[i] = c;
                while(t!=i)
                {
                    count++;
                    vis[t] = c;
                    t = mp[t];
                }
                hash[c] = count;
                c++;
            }
        }
        for(int i = 1; i<=n; i++)
        {
            ans[i] = hash[vis[i]];
        }
        for(int i = 1; i<=n; i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
}