#include <iostream>
using namespace std;
int main()
{
    string t;
    cin >> t;
    int cnt=0,pos=-1;
    for (int i=0;i<t.size();i++)
    {
        if (t[i]=='a')
        cnt++;
        if (2*(i+1)-cnt==t.size())
        {
            pos=i;
            break;
        }
    }
    if (pos==-1)
    {
        cout << ":(";
        return 0;
    }
    int cur=0;
    for (int j=pos+1;j<t.size();j++)
    {
        if (t[j]=='a')
        {
            cout << ":(";
            return 0;
        }
        while (t[cur]=='a')
        cur++;
        if (t[cur]!=t[j])
        {
            cout << ":(";
            return 0;
        }
        cur++;
    }
    cout << t.substr(0,pos+1);
}
