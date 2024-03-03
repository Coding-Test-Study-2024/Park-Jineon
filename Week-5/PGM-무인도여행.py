import sys 
sys.setrecursionlimit(10000) #재귀 한도 설정

m = []
answer = []

def find(x,y):
    global m
    global answer
    if '1' <= m[y][x]  <= '9': # 숫자면 상하좌우 탐색
        now = int(m[y][x])
        a, b, c, d = 0, 0, 0, 0
        
        m[y][x] = 'X'
        if len(m) > y+1: a = find(x,y+1)
        if len(m[0]) > x+1: b = find(x+1,y)
        if  -1 < y-1: c = find(x,y-1)
        if -1 < x-1: d = find(x-1,y)
        
        return now+a+b+c+d # 현재 숫자와 상하좌우 숫자 더한 값 리턴
    
    else: return 0 # X면 0 리턴

def solution(maps):
    global m
    for i in maps:
        m.append(list(i))
    
    for y in range(len(m)):
        for x in range(len(m[0])):
            if '1' <= m[y][x] <= '9': # 숫자면 탐색 시작
                answer.append(find(x,y))

    return sorted(answer) if len(answer) > 0 else [-1]




    
    


