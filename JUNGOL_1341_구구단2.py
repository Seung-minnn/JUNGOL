s,e = map(int,input().split())

if s<2 or e < 2 or s>9 or e > 9:
    while True:
        print("INPUT ERROR!")
        s, e = map(int, input().split())
        if(2<=s<=9 and 2<=e<=9):
            break

flag=1

if (s>e)==True:
    flag=-1


for i in range(s, e+flag, flag):
    for j in range(1, 10):
        print("%d * %d = %2d   " % (i, j, j * i), end='')
        if j % 3 ==0:
            print()
    print()
