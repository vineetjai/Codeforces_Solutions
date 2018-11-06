#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int n,p;
	cin>>n;
	double sum=0;
	for(int i=0;i<n;i++){
		cin>>p;
		sum+=(double)p;
	}
	cout<<fixed<<setprecision(12)<<sum/float(n)<<endl;
}