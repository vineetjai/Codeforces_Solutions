#include <iostream>
using namespace std;
string decToBinary(long long  n) { 
	string s="";
    for (int i = 31; i >= 0; i--) { 
        long long k = n >> i; 
        if (k & 1) 
            s+="1"; 
        else
            s+="0"; 
    }
    return s; 
} 
int main(){
	long long x;
	cin>>x;	
	string h=decToBinary(x);
	int c=0;
	for(int i=0;i<h.length();i++){
		if(h[i]=='1') c+=1;
	}
	cout<<c<<endl;
}