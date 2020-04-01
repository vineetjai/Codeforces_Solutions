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
int main(){
	optimizeIO();
    int x,y,z,l;
    cout<<"? 1 2"<<endl;
    cin>>q[0];
    cout<<"? 3 4"<<endl;
    cin>>q[1];
    cout<<"? 5 6"<<endl;
    cin>>q[2];
    
    map<int,pair<int,int> > m;
    std::vector<pair<int,int>> v(3);
    for(int i=0;i<3;i++){
        if(q[i]%23==0){
            if(i==0){
                m[23]=MP(1,2);
                v[1]=(MP(1,2));
            }
            else if(i==1){
                m[23]=MP(3,4);
                v[1]=(MP(3,4));
            }
            else if(i==2){
                m[23]=MP(5,6);
                v[1]=(MP(5,6));
            }
        }
        if(q[i]%15==0){
            if(i==0){
                m[15]=MP(1,2);
                v[0]=(MP(1,2));
            }
            else if(i==1){
                m[15]=MP(3,4);
                v[0]=(MP(3,4));
            }
            else if(i==2){
                m[15]=MP(5,6);
                v[0]=(MP(5,6));
            }
        }
        if(q[i]%7==0){
            if(i==0){
                m[42]=MP(1,2);
                v[2]=(MP(1,2));
            }
            else if(i==1){
                m[42]=MP(3,4);
                v[2]=(MP(3,4));
            }
            else if(i==2){
                m[42]=MP(5,6);
                v[2]=(MP(5,6));
            }
        }
    }
    int flag=0;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(v[i]==v[j]){
                flag=1;
                cout<<"? ";
                
            }
        }
    }
    
    cout<<"? 1 4"<<endl;
    cin>>q[3];

 //    cin.clear();
 //    int a[6]={4,8,16,15,42,23};
 //    int x,y,z;
 //    cin>>x;
 //    cout<<"? 2 2"<<endl;
 //    cin.clear();
 //    cin>>y;
 //    std::vector<int> v;
 //    for(int i=0;i<6;i++){
 //        if(a[i]!=sqrt(x) && a[i]!=sqrt(y)) v.push_back(a[i]);
 //    }
 //    map<int,int> m;
 //    m[1]=sqrt(x);
 //    m[2]=sqrt(y);
 //    cout<<"? 3 5"<<endl;
 //    cin.clear();
 //    cin>>z;
 //    for(int i=0;i<4;i++){
 //        for(int j=i+1;j<4;j++){
 //            if(v[i]*v[j]==z){
 //                m[3]=min(v[i],v[j]);
 //                m[5]=max(v[i],v[j]);
 //            }
 //        }
 //    }
 //    cout<<"? 4 6"<<endl;
 //    cin.clear();
 //    cin>>z;
 //    for(int i=0;i<4;i++){
 //        for(int j=i+1;j<4;j++){
 //            if(v[i]*v[j]==z){
 //                m[4]=min(v[i],v[j]);
 //                m[6]=max(v[i],v[j]);
 //            }
 //        }
 //    }
 //    cout<<"!";
 //    for(auto i:m){
 //        cout<<" "<<i.second;
 //    }
 //    cout<<endl;
	// return 0;
}