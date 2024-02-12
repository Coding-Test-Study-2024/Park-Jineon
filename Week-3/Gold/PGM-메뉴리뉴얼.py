
m =[]
comb = []

def combination(start, n, s):
    s = s + m[start]
    global comb
    
    if n==1:
        comb.append(s)
    
    for i in range(start+1,len(m)):
        combination(i,n-1, s)
                   
def solution(orders, course):
    answer = []
    menu = set()
    global m
    
    for i in orders:
        for j in i:
            menu.add(j)
    
    m = sorted(list(menu))
    
    for i in course:
        for j in range(len(m)):
            combination(j, i, "")
    
    l = len(comb[0])
    M = 2
    a = []
    
    for i in comb:
        cnt = 0
        for k in orders:
            have = True
            for j in i:
                if j not in k:
                    have = False
                    break
            if have: cnt+=1

        
        if l != len(i):
            for x in a:
                answer.append(x)
            a = []
            M = 2
        
        if cnt == M:
            a.append(i)
        elif cnt >= M:
            a = []
            a.append(i)
            M = cnt

        l = len(i)
    
    for x in a:
        answer.append(x)

    answer.sort()

    return answer
