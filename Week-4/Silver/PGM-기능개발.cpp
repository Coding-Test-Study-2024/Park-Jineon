#include <string>
#include <vector>

using namespace std;

//첫 번째 풀이
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 1;
    int std = (100 - progresses[0])/speeds[0] +( (100 - progresses[0])%speeds[0] > 0 ? 1 : 0); // 배포 기준점
 
    for(int i = 1; i < progresses.size();i++){
        
        int now = (100 - progresses[i])/speeds[i] +( (100 - progresses[i])%speeds[i] > 0 ? 1 : 0); // 현재 기능 완료까지 걸리는 시간
        if(now <= std) day++; // 기준점과 같거나 기준점보다 작으면 같이 배포
        else{ // 기준점보다 크면 다음 배포에 들어감
            answer.push_back(day);
            day = 1;
            std = now; //기준점을 현재 기능 완료까지 걸리는 시간으로 재정의
        }
    }
    answer.push_back(day); //마지막 배포
    return answer;
}

//두 번째 풀이
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
  
    int cnt = 0; // 현재 날짜
    int day = 0; // 기준점
    for(int i = 0 ; i < progresses.size(); i++){
        while(progresses[i]+speeds[i]*cnt < 100) cnt += 1; //진행률이 100 넘을 때까지 날짜 1씩 올리기
        
        if(day != cnt){ // 날짜가 지나면 새로 배포
            day = cnt;
            answer.push_back(1);
        }else{ //날짜가 같으면(현재 날짜 전부터 배포가능했다면) 같이 배포
            *(answer.end()-1) += 1;
        }
    }

    return answer;
}
