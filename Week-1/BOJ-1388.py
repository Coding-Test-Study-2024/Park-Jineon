cnt = 0 # cnt = 나무 판자 개수
same = False # same = 같은 판자인지 여부
    
# 입력값 받기
h , w = map(int,input().split()) # w = 가로, h = 세로
arr = [] # 나무 판자 배열
for i in range(h):
    arr.append(input().strip(''))
    
# 가로 판자 개수 세기
for i in range(h):
    same = False;
    for j in range(w):
        if arr[i][j]=='-' and not same:
            cnt+=1
            same = True
        elif arr[i][j]=='|':
            same = False

# 세로 판자 개수 세기
for i in range(w):
    same = False;
    for j in range(h):
        if arr[j][i]=='|' and not same:
            cnt+=1
            same = True
        elif arr[j][i]=='-':
            same = False
    
# 출력
print(cnt)
