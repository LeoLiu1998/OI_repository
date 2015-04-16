def C(n,m):
    return fact[n]/fact[m]/fact[n-m];
f=raw_input().split(" ");
n=int(f[0]);
m=int(f[1]);
tot=max(n,m)*2;
fact=[1];
for i in range(1,tot+1):
    fact.append(fact[-1]*i);
c=n-m;
ans=C(tot-c,tot/2)-C(tot-c,tot/2+1);
print ans;