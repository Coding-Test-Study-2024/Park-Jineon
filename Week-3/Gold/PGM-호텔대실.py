import heapq

def plusTen(time): # 10분 더해주는 함수
    a = int(time[:2]) # 시간 추출
    b = int(time[3:])+10 # 분 추출 후 10분 더하기
    
    if b >= 60: # 60분 넘으면 1시간 더해주고 60분 빼기
        a += 1
        b -= 60
    
    hour = str(a)
    minute = str(b)
    
    if len(hour) == 1: hour = '0' + hour # 한 자리 수이면 앞에 0 추가
    if len(minute) == 1: minute = '0' + minute # 한 자리 수이면 앞에 0 추가
    
    return hour+':'+minute //형식 맞춰주기

def solution(book_time):
    book_time.sort() // 오름차순 정렬
    pq = []
    heapq.heappush(pq,plusTen(book_time[0][1])) 
    for i in range(1,len(book_time)):
        if book_time[i][0] >= pq[0]:// 제일 빨리 끝나는 객실 + 10 보다 시작시간이 늦으면 같은 객실 쓰기
            heapq.heappop(pq)
            
        heapq.heappush(pq,plusTen(book_time[i][1]))

    return len(pq)
