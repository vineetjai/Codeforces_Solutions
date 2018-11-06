#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
#define pb push_back
#define ll long long 
using namespace std;

string getString(char x) { 
    string s(1, x); 
    return s;    
} 
int main(){
	int t;
	cin>>t;
	for(int o=0;o<t+1;o++){
		string s;
		vector<string > v;
		getline(cin,s);
		string g="";
		for(int i=0;i<s.length();i++){
			if(s[i]==' '){ v.pb(g); g="";}
			else g=g+s[i];
		}
		v.pb(g);
		for(int i=0;i<v.size();i++){
			char f=tolower(v[i][0]);
			if(v[i].length()!=1){
				string d=getString(f)+"ay";
				string ans="";
				for(int j=1;j<v[i].length();j++){
					if(j==1 && i==0) ans+=toupper(v[i][1]);
					else if(j==1 && i>0) ans+=tolower(v[i][1]);
					else ans+=v[i][j];
				}
				ans=ans+d;
				v[i]=ans;
			}
			else{
				if(i==0)v[i]=getString(toupper(v[i][0]))+"ay";
				else v[i]=getString(tolower(v[i][0]))+"ay";
			}
		}
		if(o!=0){
			for(int i=0;i<v.size();i++){
				cout<<v[i]<<" ";
			}
			cout<<endl;
		}
	}
}