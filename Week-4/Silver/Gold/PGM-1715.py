import heapq
pq = []

n = int(input())

for i in range(n):
    m = int(input())
    heapq.heappush(pq,m)

answer = 0                      

while len(pq) != 1 : # 큐에 가장 작은 두 수를 pop하고 더한 다음 더한 결과값 다시 큐에 pust
    a = heapq.heappop(pq)
    b = heapq.heappop(pq)
    answer += (a+b) # 비교 횟 수 전체 더하기
    heapq.heappush(pq,(a+b))

print(answer)

