#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long 
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int x1,x2,x3;
	cin>>x1>>x2>>x3;
	int min1=1000;
	for(int i=1;i<=100;i++){
		min1=min(min1,abs(i-x1)+abs(i-x2)+abs(i-x3));
	}
	cout<<min1<<endl;
}