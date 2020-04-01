#include <iostream>
using namespace std;
int n25, n50, a, bad;
int main(){
	int n;
	cin>>n;
	n25 = n50 = 0; bad = 0;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a);
        if (a == 25) n25++; else
            if (a == 50) {
                if (n25 == 0) { cout << "NO" << endl; bad = 1; break; }
                else { n50++; n25--; }
            } else
            {
                if (n50 > 0 && n25 > 0) { n50--; n25--; } else
                    if (n25 >= 3) { n25 -= 3; } else { cout << "NO" << endl; bad = 1; break; }
            }
    }
    if (!bad) cout <<"YES" << endl;
}