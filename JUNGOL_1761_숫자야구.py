n=int(input())
a_list=[]
b_list=[]
#strike=[]
#ball=[]

for i in range(n):
    t1, t2, t3=map(int, input().split())
    a_list.append(str(t1))
    #strike.append(t2)
    #ball.append(t3)
    b_list.append((t2,t3))

#print(a_list, b_list)

count=0

for i in range(123,988):
    t=str(i)
    if t[0]==t[1] or t[1]==t[2] or t[2]==t[0]:
        continue
    if t[0]=='0' or t[1]=='0' or t[2]=='0':
        continue
    TF = True

    for index, j in enumerate(a_list):
        ball = 0
        strike = 0

        #스트라이크 비교
        if t[0]==j[0]:
            strike+=1
        if t[1]==j[1]:
            strike+=1
        if t[2]==j[2]:
            strike+=1
        if b_list[index][0]!=strike:
            TF=False

        #볼 비교
        if t[0] in j:
            ball+=1
        if t[1] in j:
            ball+=1
        if t[2] in j:
            ball+=1
        ball=ball-strike
        if b_list[index][1]!=ball:
            TF=False

    if TF==True:
        count+=1

print(count)

'''
4
123 1 1
356 1 0
327 2 0
489 0 1
->2
'''

