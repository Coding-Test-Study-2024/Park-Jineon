def solution(storey):
    answer = 0
    i = storey
  
    while i > 0:
        r = i%10 # 첫 번째 자리 숫자 확인
        r2 = (i//10)%10 # 두 번째 자리 숫자 확인
      
        if r < 5 or (r == 5 and r2 < 5): answer+= r # 첫 번째 자리 숫자가 5보다 작거나, 5와 같은데 두 번째 자리 숫자가 5보다 작은 경우 r 더하기 
        else: # 첫 번째 자리 숫자가 5보다 크거나, 5와 같은데 두 번째 자리 숫자가 5와 같거나 큰 경우 10-r 더하고, 다음 자리 숫자 1 더하기
            answer += 10-r
            i += 10
          
        i //= 10
      
    return answer
