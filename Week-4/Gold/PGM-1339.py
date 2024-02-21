answer = 0
cnt = dict()
n = int(input())
 
for i in range(n):
    a = input().strip();
    digit = 1
    for j in range(len(a)-1,-1,-1): # 각 string의 알파벳 별로 자릿수 더해주기
        if a[j] in cnt:
            cnt[a[j]]+= digit
        else:
            cnt[a[j]] = digit
        
        digit *= 10

result = sorted(cnt.values(),reverse=True) 

m = 9
for i in range(len(result)): # 각 알파벳 별로 큰 순서대로 큰 숫자 부여해서 더해주기
    answer += m*result[i]
    m-=1

print(answer)
