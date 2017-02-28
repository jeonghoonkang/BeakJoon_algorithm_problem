# -*- coding: utf-8 -*-

stack=[]
list=[]
result = []
a = input()
for i in range(a):
    list.append(input())
num=1
valid=True
for point in list:
    while(num<=point):
        stack.append(num)
        result.append("+")
        num = num + 1
    if stack[-1]==point:
        stack.pop(-1)
        result.append("-")
    else:
        valid=False
        break

if valid==False  :
    print "NO"
else:
    for v in result:
        print v
#진짜 중요한 발상은 스택이라함은 맨 위에서부터 하나씩 차례로 감소하는 구조이다. 차례로 하나씩 제거해야한다는 점을 활용해서 순열을 표현하고 표현하지 못하는것을 알 수 있게 되는데
#만약 현재 스택의 맨 위의 값보다 작은 값을 꺼낼 경우에는 그 맨 위에값도 없애고 꺼내야 하기 때문에 그 순열은 표현할 수 없게 된다.
# 그 외의 순열로 표현할 수 없는 경우는 없다.