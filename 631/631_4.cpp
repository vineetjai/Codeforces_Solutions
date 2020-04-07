#include<bits/stdc++.h>
void solve(){
   int d, m;
   scanf("%d%d",&d, &m);
   long long answer=1;
   for(int i = 0; i < 30; i++) {
       if(d < (1 << i)) break;
       // choose between [2^𝑣,𝑚𝑖𝑛(2^(𝑣+1)−1,𝑑)] or nothing can be choosen

       answer = answer * (std::min((1 << (i+1)) - 1, d) - (1 << i) + 2) % m;
   }
   // rejecting case where nothing is choosen (snce n>1)
   answer--;
   if(answer < 0) answer += m;
   printf("%lld\n",answer);
}
int main() {
   int T;
   scanf("%d", &T);
   while(T--) {
       solve();
   }
}
