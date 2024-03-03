# 악보 # 변환
def convertInfo(m):
    if "C#" in m: m = m.replace("C#","c")
    if "D#" in m: m = m.replace("D#","d")
    if "F#" in m: m = m.replace("F#","f")
    if "G#" in m: m = m.replace("G#","g")
    if "A#" in m: m = m.replace("A#","a")
    if "B#" in m: m = m.replace("B#","b")
    return m


def solution(m, musicinfos):
    answer = []
    info = []
    candidate = []    
    m = convertInfo(m)

  # 입력값 변환
    for i in musicinfos:
        info.append(i.split(','))

        hour = int(info[-1][1][0:2])- int(info[-1][0][0:2])
        minute = int(info[-1][1][3:5])- int(info[-1][0][3:5])
        time = hour*60+minute
    
        a = ""
        b = convertInfo(info[-1][3])

        while len(a) < time : a += b
        info[-1][3] = a[:time] # 악보 재조정
        info[-1].append(time) # 시간

    # 해당 음악 candidate에 넣기
    for i in range(len(info)):
        print(info[i][3])
        if m in info[i][3]:
            candidate.append([info[i][2],info[i][4]])

    # 답 반환
    if len(candidate) > 1: # 해당 음악 1개 초과
        max = 0
        for i in range(len(candidate)): # 시간 제일 긴 음악 고르기
            if max < candidate[i][1]:
                answer = []
                answer.append(candidate[i][0])
                max = candidate[i][1]
                                        
            elif max == candidate[i][1]: answer.append(candidate[i][0])

        return answer[0] # 시간 제일 긴 음악 중 첫 번째 입력된 음악 반환
      
    elif len(candidate) == 1:
        return candidate[0][0] # 답 반환
      
    else:
        return "(None)" # 해당 음악 없을 때 반환
    
