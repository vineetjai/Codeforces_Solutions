#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3+10;
int a[N],n,m,q=1e8,d=20000;
bool solve(){
    int k=0;
    for(int i=0;i<n;++i) k+=i/2;
    if(k<m) return false;
    for(int i=1;i<=n;++i){
        if(m==0){
            a[i]=d*i+q;
        }
        else if((i-1)/2>m){
            a[i]=2*i-2*m-1;
            m=0;
        }
        else{
            m-=(i-1)/2; a[i]=i;
        }
    }
    return true;
}
int main(){
    scanf("%d %d",&n,&m);
    if(solve()){
        for(int i=1;i<=n;++i)
            printf("%d ",a[i]);
    }
    else printf("-1\n");
}