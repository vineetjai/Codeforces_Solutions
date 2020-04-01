## E solution
n=int(input())
l1= [int(x) for x in input().split()]
l2= [int(x) for x in input().split()]

for i in range(len(l1)):
	l1[i]=l1[i]*(i+1)*(n-i);

l1.sort()
l2.sort(reverse=True)

MOD=998244353
ans=0

for i in range(len(l1)):
	ans=ans+l1[i]*l2[i]
	ans=ans%MOD;
print(ans)