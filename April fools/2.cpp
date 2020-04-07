#include <bits/stdc++.h>
#include <set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> s;
    int z=n;
    for(int i=2;i<=(z);i++) {
        while(n%i==0){
            s.push_back(i);
            n=n/i;
        }
    }
    for(auto i:s) cout<<i;
    cout<<endl;
    // string ans=to_string(*s.begin())+to_string(*(s.end()));
    // cout<<ans<<endl;
    return 0;
}
