import sys
# 하노이 탑
def hanoi(start, end, middle, n):
    if n == 0: return
    hanoi(start, middle, end, n-1) # n-1개 탑 시작에서 중간으로 옮기기
    print(str(start)+' '+str(end))
    hanoi(middle, end, start, n-1) # n-1개 탑 중간에서 목표로 옮기기

n = int(sys.stdin.readline())
print(2**n - 1) # 탑 이동 횟수 = 2**(탑 개수)-1
hanoi(1,3,2,n)
