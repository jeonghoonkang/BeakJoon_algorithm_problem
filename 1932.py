# -*- coding: utf-8 -*-
"""
문제
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
위 그림은 크기가 5인 숫자 삼각형의 한 모습이다.

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 숫자는 모두 정수이며, 범위는 0 이상 99 이하이다.

입력
첫째 줄에 삼각형의 크기 n(1≤n≤500)이 주어지고, 둘째 줄부터 n+1줄까지 숫자 삼각형이 주어진다.

출력
첫째 줄에는 최대가 되는 합을 출력한다.

예제 입력  복사
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
예제 출력  복사
30
"""

def triangle(x,y,array,time_Array):

    if x==len(array)-1:
        time_Array[x][y]=int(array[x][y])
        return int(array[x][y])
    else:
        if isinstance(time_Array[x+1][y],int):
            left=time_Array[x+1][y]
        else:
            left=triangle(x+1,y,array,time_Array)
        if isinstance(time_Array[x+1][y+1],int):
            right=time_Array[x+1][y+1]
        else:
            right=triangle(x+1,y+1,array,time_Array)
        if left>right:
            time_Array[x][y]=left+int(array[x][y])
            return time_Array[x][y]
        else:
            time_Array[x][y] = right+int(array[x][y])
            return time_Array[x][y]

a=input()
array=[]
for i in range(a):
    b=raw_input()
    array.append(b.split())

time_Array=array
print triangle(0,0,array,time_Array)

"""
시간초과가 나는 풀이법-> 이미 구해진 값을 따로 저장해놓고 재활용 하는 방법이 필요하다.
def triangle(x,y,array):

    if x==len(array)-1:
        return int(array[x][y])
    else:
        left=triangle(x+1,y,array)
        right=triangle(x+1,y+1,array)
        if left>right:
            return left+int(array[x][y])
        else:
            return right+int(array[x][y])

a=input()
array=[]
for i in range(a):
    b=raw_input()
    array.append(b.split())

print triangle(0,0,array)
"""