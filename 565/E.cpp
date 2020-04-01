#include <iostream>
using namespace std;
typedef long int ulli; 
vector<ulli> ans;
map<ulli,int> m;
vector<ulli> sieve(){
    ulli n=2750131;
    vector<bool> prime(n+1,true); 
       
    prime[0] = false; 
    prime[1] = false; 
    int m = sqrt(n);
    for (ulli p=2; p<=m; p++){
        if (prime[p]){
            for (ulli i=p*2; i<=n; i += p) 
            prime[i] = false; 
        } 
    }
    int c=1;
    for (int i=0;i<n;i++) 
        if (prime[i]){
            ans.push_back(i); 
            m[i]=c;
            c++;
        } 
} 

int main(){
    ulli n;
    cin>>n;
    ulli i,a[n],b[2*n];
    for( i=0;i<2*n;i++) cin>>b[i];
    
}