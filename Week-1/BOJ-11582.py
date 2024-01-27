# 입력값 받기
n = int(input()) # n = 정렬할 숫자 갯수
num = list(map(int,input().split())) # num = 정렬할 숫자 배열
mem = int(input()) # mem = 회원 수
    
# 각 사람당 앞에서부터 차례대로 (n/mem)개의 숫자 정렬
for i in range(mem):
    num[i*(n//mem):(i+1)*(n//mem)] = sorted(num[i*(n//mem):(i+1)*(n//mem)])
    
# 출력
for i in num: print(str(i),end=' ')
