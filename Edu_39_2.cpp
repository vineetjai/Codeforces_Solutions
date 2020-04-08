#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  string str="abcdefghijklmnopqrstuvwxyz";
  int ch=0;
  for(int i=0;i<s.length(); i++ ){
    if(ch==26) break;
    if(s[i]<='a'+ch) {s[i]='a'+ch;ch++;}
  }
  if(ch!=26) cout<<-1<<endl;
  else cout<<s<<endl;
}
