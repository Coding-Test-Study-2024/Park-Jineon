def count(x, y, n):
    std = arr[y][x] # 첫 종이가 기준점
    same = True # 첫 종이랑 같은 색깔인지 확인
    
    for i in range(y,y+n):
        for j in range(x, x+n):
            if arr[i][j] != std: # 기준점과 색깔이 다르면 same을 False로 바꾸고 반복문 빠져 나가기
                same=False 
                break
        if not same: # 반복문 빠져 나가기
            break
    
    if same: # 모든 종이가 같은 색이면 1 더하기
        global blue # 지역 변수 global 선언
        global white # 지역 변수 global 선언
        if std: blue += 1
        else: white += 1
    else: # 종이 하나라도 다른 색이면 4분할로 나누기
        count(x, y, n//2)
        count(x, y+n//2, n//2)
        count(x+n//2, y, n//2)
        count(x+n//2, y+n//2, n//2)

# 입력 받기
n = int(input())
white = 0
blue = 0
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))
    
count(0, 0, n)

# 출력
print(white)
print(blue)
