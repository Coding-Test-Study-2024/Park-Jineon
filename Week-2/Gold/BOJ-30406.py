# 0은 3, 2, 1 ,0 순으로 큰 점수 획득
# 1은 2, 3, 0, 1 순으로 큰 점수 획득
# 2는 1, 0, 3, 2 순으로 큰 점수 획득
# 3은 0, 1, 2, 3 순으로 큰 점수 획득

def calculate(point, end, plus, pair):
    cnt = 0
    global result
    global price
    for i in range(0, end, plus):
        cnt = min(price[i],price[abs(i+pair)]) # 선물 쌍 개수 확인
        result += point*cnt # 만족도 계산
        price[i] -= cnt # 개수 차감
        price[abs(i+pair)] -= cnt # 개수 차감


N = int(input())
price = [0, 0, 0, 0]
result = 0
arr = list(map(int,input().split()))

# 가격별 선물 개수 입력
for i in arr:
    price[i]+=1
    
calculate(3, 2, 1, -3); # 3점 확인
calculate(2, 2, 1, 2); # 2점 확인
calculate(1, 3, 2, 1); # 1점 확인
    
print(result)
