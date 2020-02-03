n=int(input())
a=[[0]*n for k in range(n)]
cnt=0
flag=0
dx=-1
dy=-1
for i in range(n,0,-1):
    for j in range(0,i,1):
       if (flag%3)==0:
            dx+=1
            dy+=1
            a[dx][dy]=cnt
            cnt+=1
       elif (flag%3)==1:
            dy-=1
            a[dx][dy]=cnt
            cnt+=1
       elif (flag%3)==2:
            dx-=1
            a[dx][dy]=cnt
            cnt+=1
    flag+=1

for i in range(0,n):
    for j in range (0,i+1):
        print("{0} ".format(a[i][j]%10),end="")
    print()