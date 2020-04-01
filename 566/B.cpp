#include <iostream>
#include <vector>
using namespace std;
int main(){
	int h,w;
	cin>>h>>w;
	char a[h][w];
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++) cin>>a[i][j];

	int flag=0,flag1=0,c=-1,r=-1;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(a[i][j]=='*' && flag==0){
				c=j;
				flag=1;
			}
			else if(flag1==0 && a[i][j]=='*' && j!=c){
				r=i;
				flag1=1;
			}
		}
	}	
	if(r==0 || r==h-1 || c==w-1 || c==0 || r==-1 || c==-1){
		cout<<"NO\n";
		return 0;
	}

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(a[i][j]=='*' && (i!=r && j!=c)){
				cout<<"NO\n";
				return 0;
			}
		}
	}

	int flag2=0;
	for(int i=0;i<r;i++){
		int k=0;
		for(int j=0;j<w;j++){
			if(a[i][j]=='*' && j!=c){
				cout<<"NO\n";
				return 0;
			}
			else if(a[i][j]=='*'){
				k++;
				flag2=1;
			}
		}
		if(k!=1 && flag2==1){
			cout<<"NO\n";
			return 0;
		}
	}

	std::vector<int> v;
	for(int j=0;j<w;j++){
		if(a[r][j]=='*')v.push_back(j);
	}
	if(v.size()<3){
		cout<<"NO\n";
		return 0;
	}

	int flag3=0;
	for(int i=0;i<v.size();i++){
		if(v[i]==c && (i==0 || i==v.size()-1)){
			cout<<"NO\n";
			return 0;
		}
	}

	for(int i=1;i<v.size();i++){
		if(v[i]!=v[i-1]+1){
			cout<<"NO\n";
			return 0;
		}
	}


	flag=0;
	int f=0;
	for(int i=r+1;i<h;i++){
		int k=0;
		for(int j=0;j<w;j++){
			if(a[i][j]=='*' && j!=c){
				cout<<"NO\n";
				return 0;
			}
			else if(a[i][j]=='*'){
				k++;
				f=1;
			}

		}
		if(k==0){
			flag=1;
		}
		if((k!=1 && flag==0) || (flag==1 && k!=0)){
			cout<<"NO\n";
			return 0;
		}
	}
	if(f==0) cout<<"NO\n";
	else cout<<"YES\n";
}