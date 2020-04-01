#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n,x;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; i++) scanf("%d", a + i);
  	sort(a, a + n);
	int used = 0, ans = 0;
	while (used < n) {
		ans++;
		int h = 0;
		for (int i = 0; i < n; i++)
			if (a[i] >= h) {
			a[i] = -1;
			h++;
			used++;
		}
	}
	printf("%d\n", ans);
	return 0;
}