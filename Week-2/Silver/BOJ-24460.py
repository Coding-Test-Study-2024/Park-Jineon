def pickOne(x, y, n):
    # 1일때 return
    if n == 1: return arr[y][x]
      
    # 4개 구역으로 나누기
    a = pickOne(x, y, n//2)
    b = pickOne(x, y+n//2, n//2)
    c = pickOne(x+n//2, y, n//2)
    d = pickOne(x+n//2, y+n//2, n//2)

    # 두 번째로 작은 수 return
    return sorted([a,b,c,d])[1]

# 입력
n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int,input().split(' ')))) 

#출력
print(pickOne(0,0,n))
