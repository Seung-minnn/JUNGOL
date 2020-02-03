#xeqdbjorktpnvhzmfsguwyalic
#Kxbwrb ehyls rgpb rlwzir jglysnj Ub sbj HBWX NTLSHV wj jnb pbbjylsr
a=input()       #eydbkmiqugjxlvtzpnwohracsf
b=input()       #Kifq oua zarxa suar bti yaagrj fa xtfgrj
c="abcdefghijklmnopqrstuvwxyz"
d=[]
for ib, bbb in enumerate(b):
    t = 0
    for ic, ccc in enumerate(c):
        if 'A'<= bbb <='Z':
            bbb=bbb.lower()
            t=1
        if bbb==ccc:
            if t==1:
                d.append(a[ic].upper())
            else:
                d.append(a[ic])
            break
        if ic==len(c)-1:
            d.append(bbb)
    #print(d)


for i in d:
    print(i,end="")
