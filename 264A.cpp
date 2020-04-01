#include<iostream>
#include <map>
using namespace std;
void optimizeIO(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
	optimizeIO();
	string s;
	cin>>s;int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]=='r'){
			cout<<i+1<<"\n";
		}
	}
	for(int i=n-1;i>=0;i--){
		if(s[i]=='l') cout<<i+1<<"\n";
	}
}