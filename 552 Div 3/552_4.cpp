#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;
int main(){
	ll n,b,a;
	cin>>n>>b>>a;
	ll x=b,y=a;
	int s[n];
	int ans=0;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++){
		if(s[i]==1){
			if(y<a && x>0){ ans+=1;y=y+1;x=x-1;}
			// else if(y==a){ ans+=1;y=y-1;}
			else if( (y==a) || (y>0 && x==0)){ ans+=1;y=y-1;}
			else break;
		}
		else{
			if(y>0){ans+=1;y=y-1;}
			else if(x>0){ans+=1; x=x-1;}
			else break;
		}
	}
	cout<<ans<<endl;
}