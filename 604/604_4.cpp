#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a,b,c,d;
int main(){
    cin>>a>>b>>c>>d;
    
    int cnt=(a>0)+(b>0)+(c>0)+(d>0);
    if(cnt==1){
        if(a>0){
            if(a==1) {printf("YES\n0");}
            else printf("NO"); 
        }
        if(b>0){
            if(b==1) {printf("YES\n1");}
            else printf("NO"); 
        }
        if(c>0){
            if(c==1) {printf("YES\n2");}
            else printf("NO"); 
        }
        if(d>0){
            if(d==1) {printf("YES\n3");}
            else printf("NO");  
        }
        return 0;
    }
    
    
    
    
    if(c==d && c==0 && a==b+1){
        printf("YES\n0 ");
        for(int i=1;i<=b;i++) printf("1 0 ");
        return 0;
    }
    if(a==b && a==0 && d==c+1){
        printf("YES\n3 ");
        for(int i=1;i<=c;i++) printf("2 3 ");
        return 0;
    }
    

    if(a>b || d>c) {printf("NO");return 0;}
    int p=b-a,q=c-d;
    if(abs(p-q)>1) {printf("NO");return 0;}

    puts("YES");
    if(p==q){
        for(int i=1;i<=a;i++) printf("0 1 ");
        for(int i=1;i<=p;i++) printf("2 1 ");
        for(int i=1;i<=d;i++) printf("2 3 "); 
    }
    else if(p<q){
        for(int i=1;i<=a;i++) printf("0 1 ");
        for(int i=1;i<=p;i++) printf("2 1 ");
        for(int i=1;i<=d;i++) printf("2 3 ");printf("2");
    }
    else {
        printf("1 ");
        for(int i=1;i<=a;i++) printf("0 1 ");
        for(int i=1;i<=q;i++) printf("2 1 ");
        for(int i=1;i<=d;i++) printf("2 3 ");
    }
    return 0;
}