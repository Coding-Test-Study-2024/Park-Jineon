while True:
    try:
        # 입력값 받기 
        N = int(input())   
        str = '-'
        
        # 출력값은 str + 공백 + str 의 반복으로 이루어져 있다. 
        for i in range(N) : str = str+' '*len(str)+str;
        
        # 출력
        print(str)
    except:
        break
