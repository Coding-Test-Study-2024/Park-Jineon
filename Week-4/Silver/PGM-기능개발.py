# 첫 번째 풀이
def solution(progresses, speeds):
    answer = []

    day = 1 # 같이 배포되는 기능 개수
    std = (100 - progresses[0])//speeds[0] +(1 if (100 - progresses[0])%speeds[0] > 0  else 0) # 기준점

    for i in range(1,len(speeds)):
        
        now = (100 - progresses[i])//speeds[i] +(1 if (100 - progresses[i])%speeds[i] > 0  else 0) # 현재 기능 완료까지 걸리는 시간
        if now <= std: day+=1 # 기준점과 같거나 기준점보다 작으면 같이 배포
        else: # 기준점보다 크면
            answer.append(day) # 기존 기능들 배포
            day = 1 # 다음 배포에 넣기
            std = now # 기준점은 현재 기능

    answer.append(day) # 마지막 배포
  
    return answer


#두 번째 풀이
def solution(progresses, speeds):
    answer = []
  
    cnt = 0  # 현재 날짜
    day = 0  # 기준점
    for i in range(len(progresses)):
        while progresses[i]+speeds[i]*cnt < 100: cnt += 1 # 진행률이 100 넘는날까지 날짜 지나기
        
        if day != cnt: # 기준점과 다르면 다음 배포
            day = cnt
            answer.append(1)
        else: # 같으면 같이 배포
            answer[-1] += 1

    return answer
