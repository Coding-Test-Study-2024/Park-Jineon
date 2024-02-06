S = input().strip()
T = input().strip()

//거꾸로 풀기
while len(S) != len(T) : // S와 T가 같은 길이면 멈춤
    if T[len(T)-1] == 'B': // T 맨마지막이  B일 때
        T = T[:len(T)-1] // 맨 마지막 삭제
        T = T[::-1] // 뒤집기
    else: // T 맨 마지막이 A일 때
        T = T[:len(T)-1] // 맨 마지막 삭제

result = 1 if T==S else 0 
print(result)
