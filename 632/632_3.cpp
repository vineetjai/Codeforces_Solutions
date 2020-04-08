#include <iostream>
#include <vector>
#include <map>

using namespace std;

using ll = long long;
map<ll, int> frec;

int main()
{
  int n;
  cin >> n;
  ll result = 0, sum = 0;
  int st = 1;
  frec[0] = 1;
  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    sum += val;
    st = max(st, frec[sum] + 1);
    frec[sum] = i + 1;
    result += (i + 1 - st);
  }
  cout << result;
  return 0;
}
