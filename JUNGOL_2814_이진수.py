
'''
#1번방법

a=input()   #10101 ->21
b=len(a)
ans=0

for i in range(0,b,1):
    ans+=int(a[i])*(2**(b-i-1))

print(ans)
'''

#2번방법
def change_number(a, b):
    if(b==0):
        return 0;
    return change_number(a,b-1)*2+(int(a[b-1]))
a=input()   #10101 ->21
b=len(a)
print(change_number(a, b))