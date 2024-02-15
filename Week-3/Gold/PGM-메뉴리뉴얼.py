

menu1 = set()

def combination(start, n, s, order):
    if start > len(order)-1: 
        return
        
    s = s + order[start]
    global menu1
    

    
    if n==1:
        menu1.add(''.join(sorted(list(s))))
    
    for i in range(start+1,len(order)):
        combination(i,n-1, s, order)
                   
def solution(orders, course):
    answer = []
    
    for i in course:
        for j in orders:
            for k in range(len(orders)):
                combination(k, i, "",j)
                
    comb = sorted(list(menu1),key=lambda x: (len(x), x))
    
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
