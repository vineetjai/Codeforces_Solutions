#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int flag=-1;
    int ch=1;
    for(int i=1;i<s.length();i++) if(s[i]>='0' && s[i]<='9' && s[i-1]>='A' && s[i-1]<='Z') flag++;

    if(flag){
      int x=0,y=0;
      int i=1;
      while(s[i]>='0' && s[i]<='9') x=x*10+s[i]-'0',i++;
      if(s[i]=='C') i++;
      while(s[i]>='0' && s[i]<='9') y=y*10+s[i]-'0',i++;
      string z="";
      while(y>0){
        if(y%26) z+='A'-1+y%26;
        else z+='Z',y-=26;
        y=y/26;
      }
      reverse(z.begin(),z.end());
      cout<<z+to_string(x)<<endl;
    }
    else{
      int x=0,y=0,i=0,n=s.length();
      while(s[i]>='A' && s[i]<='Z') i++;
      string str=s.substr(0,i);
      while(i<n) y=y*10+s[i]-'0',i++;
      i=0;
      while(i<str.length()) x=x*26+str[i]-'A'+1,i++;
      cout<<'R'<<y<<'C'<<x<<endl;
    }
  }
}
