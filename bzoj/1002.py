n=int(input())
b=[0,1,1,4,3]
for c in range(5,n+1):
        b.append(3*b[c-2]-b[c-4])
if n % 2==1:
        print(b[n]*b[n])
else:
        print(5*b[n]*b[n])]])]])]]))]))
