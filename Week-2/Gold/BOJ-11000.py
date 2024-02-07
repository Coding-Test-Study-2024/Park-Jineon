#input 쓰면 시간 초과납니다.
import sys, heapq

class_list = []

n = int(sys.stdin.readline())
for i in range(n):
    s, t = map(int, sys.stdin.readline().split())
    class_list.append([s,t])    

class_list.sort()

heap = []
heapq.heappush(heap,class_list[0][1])

for i in range(1, n):
    if(heap[0] <= class_list[i][0]):
        heapq.heappop(heap)
    heapq.heappush(heap,class_list[i][1])

print(len(heap))
