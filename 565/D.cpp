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

#define LL long long 
#define PB push_back
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

class Graph{ 
    int V;  
    list<int> *adj; 
    void DFSUtil(int v, bool visited[],bool e); 
public: 
    Graph(int V);   
    void addEdge(int v, int w); 
    void  DFS(int v); 
}; 
Graph::Graph(int V){ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w){ 
    adj[v].push_back(w);
    adj[w].push_back(v);
} 
vector<int> v1,v2;
void Graph::DFSUtil(int v, bool visited[],bool e){
    if(e) {v1.push_back(v+1);}
    else {v2.push_back(v+1);}
    visited[v] = true;
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited,!e); 
}
void Graph::DFS(int v){ 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false;
    int x=0,y=0;
    DFSUtil(v, visited,true); 
} 
int main(){
	optimizeIO();
    int t,x,y;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        Graph g(n);
        for(int i=0;i<m;i++){
            cin>>x>>y;
            g.addEdge(x-1, y-1);
        }
        g.DFS(0);
        if(v1.size()<=v2.size()){
            cout<<v1.size()<<endl;
            for(int i=0;i<v1.size()-1;i++){
                cout<<v1[i]<<" ";
            }
            cout<<v1[v1.size()-1]<<endl;
        }
        else{
             cout<<v2.size()<<endl;
            for(int i=0;i<v2.size()-1;i++){
                cout<<v2[i]<<" ";
            }
            cout<<v2[v2.size()-1]<<endl;
        }
        v1.clear();
        v2.clear();
    }
    
	return 0;
}