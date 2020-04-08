#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int mask = 0;
		int n = s.size();
    // storing only numbers values
		for(int i = 0; i < n; i++) s[i] -= '0';

    // elements with frequency even will cancel out
		for(int i = 0; i < n - 1; i++) mask ^= (1 << s[i]);

    //
		bool found = false;
		for(int i = n - 2; i >= -1 && !found; i--)
		{
			int lft = n - i - 2;
			for(int j = s[i + 1] - 1; j >= (i == -1) && !found; j--)
			{
				int newMask = mask ^ (1 << j);
				int bits = __builtin_popcount(newMask);
				if(bits <= lft)
				{
					found = true;
					for(int j = 0; j <= i; j++)
						cout << (int)s[j];
					cout << j;
					for(int i = 0; i < lft - bits; i++)
					{
						cout << 9;
					}
					for(int k = 9; k >= 0; k--)
					{
						if(newMask & (1 << k))
							cout << k;
					}
				}
			}
			mask ^= (1 << s[i]);
		}

    // less digits
		if(!found){
      string str(s.size()-2,'9');
			cout<<str;
		}
		cout << endl;
    
  }
  return 0;
}
