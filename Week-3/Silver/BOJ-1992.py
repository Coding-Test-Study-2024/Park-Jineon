import sys # sys.stdin.readline()

def compress(x,y,n):
    if n == 1: return video[y][x] # 길이 1일 때 return

    # 4분할
    a = compress(x, y, n//2)
    b = compress(x+n//2, y, n// 2)
    c = compress(x, y+n//2, n// 2)
    d = compress(x+n//2, y+n//2, n//2)

  
    if len(a) ==1 and a == b and b == c and c == d: return  a # 4분할 각 결과값이 한 자리 수이고 4개 모두 같을 경우 압축
    else: return "(" + a +b + c+ d + ')' # 압축 불가

//입출력
video = []
n = int(sys.stdin.readline())
for i in range(n):
    video.append(sys.stdin.readline().strip()) 

print(compress(0, 0, n))


