#람다로 풀어보기

n=int(input())
ans=1
for i in range(n,0,-1):
    if i==1:
        print("%d! = %d"%(i,i))
    else:
        print("%d! = %d * %d!"%(i,i,i-1))
    ans=(lambda x, y: x*y)(ans, i)
print(ans)

'''
#강사님 예시
num=input()
fac=lambda n: 1 if n==0 else n*fac(n-1)
print(fac(int(num)))
'''