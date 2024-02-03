def count(x, y, n):
    std = arr[y][x]
    same = True
    
    for i in range(y,y+n):
        for j in range(x, x+n):
            if arr[i][j] != std:
                same=False
                break
        if not same: 
            break
    
    if same:
        global blue
        global white
        if std: blue += 1
        else: white += 1
    else:
        count(x, y, n//2)
        count(x, y+n//2, n//2)
        count(x+n//2, y, n//2)
        count(x+n//2, y+n//2, n//2)

n = int(input())
white = 0
blue = 0
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))
    
count(0, 0, n)
print(white)
print(blue)
