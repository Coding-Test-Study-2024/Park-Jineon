import sys

def cut(x, y, n):
    global paper
    global cnt
    
    if n==1: return paper[y][x] # 길이 1일 때 반환

    # 9 분할
    a = []
    a.append(cut(x, y ,n//3))
    a.append(cut(x+n//3, y ,n//3))
    a.append(cut(x+n//3*2, y ,n//3))
    a.append(cut(x, y+n//3 ,n//3))
    a.append(cut(x+n//3, y+n//3 ,n//3))
    a.append(cut(x+n//3*2, y+n//3 ,n//3))
    a.append(cut(x, y+n//3*2, n//3))
    a.append(cut(x+n//3, y+n//3*2,n//3))
    a.append(cut(x+n//3*2, y+n//3*2, n//3))

    # 9개 다 같은지 확인
    same = True
    
    for i in range(1,9):
        if a[i]!=a[i-1]:
            same= False
            break

    if not same:  # 하나라도 다르면 각 결과값 한 개씩 count 올려주기
        for i in range(9):
            cnt[a[i]+1]+=1
        return 2 # 세지 않아도 되는 종이 2로 반환
    else: return a[0]  # 다 같으면 대표값 한 개 반환

paper = []
cnt = [0,0,0,0]
n = int(sys.stdin.readline())
for i in range(n):
    paper.append(list(map(int,sys.stdin.readline().split())))

a = cut(0,0,n)
cnt[a+1]+=1 # 마지막 대표값 count 올려주기

print(cnt[0])
print(cnt[1])
print(cnt[2])

