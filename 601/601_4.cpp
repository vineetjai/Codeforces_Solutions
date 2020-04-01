	#include <bits/stdc++.h>
	using namespace std; 
	#define ll long long
	#define pb push_back
	#define N 1000005
	ll a[N],b[N],c[N][2],fq[N]={0},f[N]={0},T,TT=1,p=(ll)(1e9+7);
	bool mycmp(ll x,ll y){
		return (x>y);
	}
	int main(){	
		ios_base::sync_with_stdio(false); cin.tie(NULL); 
		#ifndef ONLINE_JUDGE 
		freopen("i.txt", "r", stdin);
		#endif	
		cin>>TT;
		for(T=1;T<=TT;T++){
			ll n,i,j=0,l=-1,r,k=0,m=0,ans=0,max_ele=INT_MIN,min_ele=INT_MAX,sum=0,x,y,z;
			string s1,s2,s3;
			cin>>n>>m>>k;
			string s[n];
			for(i=0;i<n;i++){
				cin>>s[i];
			}
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					if(s[i][j]=='R')
						ans++;
				}
			}
			x=ans/k;
			y=ans-x*k;
			z=k-y;
			vector<char>v;
			for(i=0;i<=9;i++){
				char c='0';
				v.pb(char(c+i));
			}
			for(i=0;i<26;i++){
				char c='a';
				v.pb(char(c+i));
			}
			for(i=0;i<26;i++){
				char c='A';
				v.pb(char(c+i));
			}
			l=0;r=0;
			for(i=0;i<n;i++){
				if(i%2==0){
					for(j=0;j<m;j++){
						if(s[i][j]=='R'){
							r++;
						}
						if(r>x){
							r=1;
							z--;
							l++;
						}
						if(z==0){
							z=-1;
							x++;
						}
						s[i][j]=v[l];
					}
				}
				else{
					for(j=m-1;j>=0;j--){
						if(s[i][j]=='R'){
							r++;
						}
						if(r>x){
							r=1;
							z--;
							l++;
						}
						if(z==0){
							z=-1;
							x++;
						}
						s[i][j]=v[l];
					}					
				}
			}
			for(i=0;i<n;i++){
				cout<<s[i]<<endl;
			}
		}
		return 0;
	}
