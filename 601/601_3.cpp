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
#define pii pair<pair<int,int >,int >
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

int check(pair<pair<int,int >,int > x, pair<pair<int,int >,int > y){
   int v[3]={x.f.f,x.f.s,x.s};
    int v1[3]={y.f.f,y.f.s,y.s};
    int c=0;
    rep(i,0,3){
        rep(j,0,3){
            if(v[i]==v1[j]) c++;
        }
    }
    return c;
}
int non_match(pair<pair<int,int >,int > x, pair<pair<int,int >,int > y){
    int v[3]={x.f.f,x.f.s,x.s};
    int v1[3]={y.f.f,y.f.s,y.s};
    int c=0;
    bool z[3]={0,0,0};
    rep(i,0,3){
        rep(j,0,3){
            if(v[i]==v1[j]) {
                z[i]=1;
            }
        }
    }
    rep(i,0,3) if(z[i]==0) c=v[i]; 
    return c;
}
int main(){
    optimizeIO();
    int n,b,c,a;
    cin>>n;
    vector<pair<pair<int,int >,int > > v;
    vector<int> graph[n+1];
    rep(i,0,n-2){
        cin>>a>>b>>c;
        v.pb(mp(mp(a,b),c));
        graph[a].pb(i);
        graph[b].pb(i);
        graph[c].pb(i);
    }
    vector<int> graph1[n-2];
    rep(i,0,v.size()){
        set<int> s1;
        pair<pair<int,int >,int > x=v[i];
        a=x.f.f,b=x.f.s,c=x.s;
        copy( graph[a].begin(), graph[a].end(), std::inserter( s1, s1.end() ) );
        copy( graph[b].begin(), graph[b].end(), std::inserter( s1, s1.end() ) );
        copy( graph[c].begin(), graph[c].end(), std::inserter( s1, s1.end() ) );
        for(auto j:s1){
            if(check(v[j],v[i])==2 && j!=i && j>i){
                graph1[j].pb(i);
                graph1[i].pb(j);
            }
        }
    }
    int vertx;
    rep(i,0,n-2){
        if(graph1[i].size()==1) {vertx=i;break;}
    }
    int vertx1;
    rep(i,0,n-2){
        if(graph1[i].size()==1 && i!=vertx) {vertx1=i;break;}
    }
    int i=0,p=-1;
    vector<int> final(n,-1);
    while(i<n-3){
        if(graph1[vertx].size()==1){
            final[i]=non_match(v[vertx],v[graph1[vertx][0]]);
            p=vertx;
            vertx=graph1[vertx][0];
            i++;
        }
        else{
            int las= graph1[vertx][0]==p ? graph1[vertx][1]:graph1[vertx][0];
            final[i]=non_match(v[vertx],v[las]);
            p=vertx;
            vertx=las;
            i++;
        }
        // cout<<p<<endl;
    }
    i=n-1,p=-1;
    while(i>=n-2){
        if(graph1[vertx1].size()==1){
            final[i]=non_match(v[vertx1],v[graph1[vertx1][0]]);
            p=vertx1;
            vertx1=graph1[vertx][0];
            i--;
        }
        else{
            int las= graph1[vertx1][0]==p ? graph1[vertx1][1]:graph1[vertx1][0];
            final[i]=non_match(v[vertx1],v[las]);
            p=vertx1;
            vertx1=las;
            i--;
        }
    }
    set<int> s2;
    rep(i,1,n+1)s2.insert(i);
    rep(i,0,n) if(s2.find(final[i])!=s2.end()) s2.erase(final[i]);
    int val=*s2.begin();
    rep(i,0,n){
        if(final[i]==-1){
            cout<<val<<" ";
        }
        else cout<<final[i]<<" ";
    }
    cout<<endl;
    return 0;
}
