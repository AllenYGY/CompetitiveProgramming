num=int(input())
forbid=[]

for i in range(num):
    word=input()
    forbid.append(word)

limit=int(input())
sentence=input()

words=[]
words=sentence.split(" ")

ans=""
count=0

for i in range(len(words)):
    for f in forbid:
        if f in words[i]:
            words.replace(f,"<censored>")

for i in range(len(words)):
    if words[i] in forbid:
        ans+="<censored>"
        count+=1
    else:
        ans+=words[i]
    ans+=" "

print(count)

if count<limit:
    print(ans)
else:
    print("He Xie Ni Quan Jia!")
# 5
# MaoNiang
# SeQing
# BaoLi
# WeiGui
# BuHeShi
# 4
# BianCheng MaoNiang ba! WeiGui De Hua Ye Keyi Shuo! BuYao BaoLi NeiRong.
