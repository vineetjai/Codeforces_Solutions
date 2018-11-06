#include <iostream>
#include <map>
using namespace std;
int main(){
	string s,g,h;
	cin>>s>>g>>h;
	map<char,int> m1;
	for(int i=0;i<s.length();i++){
		if(m1.find(s[i])!=m1.end()){
			m1[s[i]]+=1;
		}
		else m1[s[i]]=1;
	}
	for(int i=0;i<g.length();i++){
		if(m1.find(g[i])!=m1.end()){
			m1[g[i]]+=1;
		}
		else m1[g[i]]=1;
	}
	map<char,int> m;
	for(int i=0;i<h.length();i++){
		if(m.find(h[i])!=m.end()){
			m[h[i]]+=1;
		}
		else m[h[i]]=1;
	}
	if(m.size()!=m1.size()){
		cout<<"NO\n";
	}
	else{
		map<char, int>::iterator it,it1;
		int flag=1;
		for(it=m.begin(),it1=m1.begin();it!=m.end();it++,it1++){
			if(it->second != it1->second){
				flag=0; break;
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}

}