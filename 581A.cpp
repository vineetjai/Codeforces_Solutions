#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	cout<<min(a,b)<<" "<<(abs(b-a)/2)<<endl;
}