#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    for(int i = storey; i > 0; i /= 10){
        int r = i%10; // 첫번째자리 나머지 확인
        int r2 = (i/10)%10; //두번째 자리 나머지 확인
      
        if(r < 5 or (r == 5 and r2 < 5)) answer+= r; // r이 5보다 작거나, 5인데 다음 자리 숫자가 5보다 작으면 r 더하기
        else{ // r이 5보다 크거나, 5인데 다음 자리 숫자가 5와 같거나 크면 10-r 더하고 다음 자리 숫자에 1 더해주기
            answer += 10-r;
            i += 10;
        }
    }
    
    return answer;
}
