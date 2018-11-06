#include <iostream>
#include <map>
using namespace std;
int main(){
	int y;
	cin>>y;
	int i=y+1;
	while(1){
		map<int,int> m;
		if(m.find(i/1000)==m.end())m[i/1000]=1;
		else {i++; continue;}
		if(m.find((i%1000)/100)==m.end())m[(i%1000)/100]=1;
		else {i++; continue;}
		if(m.find((i%100)/10)==m.end())m[(i%100)/10]=1;
		else {i++; continue;}
		if(m.find(i%10)==m.end()){break;}
		else {i++; continue;}
	}
	cout<<i<<endl;
}