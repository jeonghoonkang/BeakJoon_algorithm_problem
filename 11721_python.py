# -*- coding: utf-8 -*-
"""
알파벳 소문자와 대문자로만 이루어진 길이가 N인 단어가 주어진다.

한 줄에 10글자씩 끊어서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 단어가 주어진다. 단어는 알파벳 소문자와 대문자로만 이루어져 있으며, 길이는 100을 넘지 않는다. 길이가 0인 단어는 주어지지 않는다.

출력
입력으로 주어진 단어를 열 개씩 끊어서 한 줄에 하나씩 출력한다. 단어의 길이가 10의 배수가 아닌 경우에는 마지막 줄에는 10개 이하의 글자만 출력할 수도 있다.

예제 입력  복사
BaekjoonOnlineJudge
예제 출력  복사
BaekjoonOn
lineJudge
예제 입력 2  복사
OneTwoThreeFourFiveSixSevenEightNineTen
예제 출력 2  복사
OneTwoThre
eFourFiveS
ixSevenEig
htNineTen
"""
stri=raw_input()
for i in range(len(stri)/10):
    print stri[i*10:i*10+10]
print stri[(i+1)*10:len(stri)+1]

#원하는 결과를 얻을 수 있지만
# 그러나 백준에서 채점시 결과가 런타임 에러가 남...원인을 찾아야함!