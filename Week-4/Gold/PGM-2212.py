n = int(input())
k = int(input())

if k >= n: # 집중국가 센서보다 많을 경우 0 출력
    print(0)
else: # 센서 정렬 후 간격 체크, 전체 간격 중 가장 긴 간격 k-1개를 제외하고 다 더해주기
    locations = sorted(list(map(int,input().split())))
    distances = sum(sorted([locations[i]-locations[i-1] for i in range(1,len(locations))])[:len(locations)-k])

    print(distances)
