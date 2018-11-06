#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int main(){
	int t,x;
	cin>>t;
	map<int ,int > m;
	m[1]=0;m[2]=0;m[3]=0;m[4]=0;
	for(int i=0;i<t;i++){
		cin>>x;
		m[x]+=1;
	}
	int count= m[4]+m[2]/2;
	m[4]=0;
	m[2]=m[2]%2;
	x=m[3];
	int y=m[1];
	m[3]=m[3]-min(x,y);
	m[1]=m[1]-min(x,y);
	count+=min(x,y);

	count+=m[1]/4;
	m[1]=m[1]%4;

	if(m[1]==0) count+=(ceil(m[2]/2.0)+ceil(m[3]/1.0));
	else if(m[3]==0 && m[1]+2*m[2]<=4)count+=1;
	else if(m[3]==0 && m[1]+2*m[2]>4)count+=2;
	else if(m[2]==0 && m[1]==0 && m[3]!=0) count+=m[3];
	else if(m[1]==0 && m[3]==0 && m[2]!=0) count+=ceil(m[2]/2);
	else if(m[2]==0 && m[3]==0 && m[1]!=0) count+=ceil(m[1]/4);
	// cout<<m[1]<<" "<<m[2]<<" "<<m[3]<<" "<<m[4]<<endl;
	cout<<count<<endl;
}