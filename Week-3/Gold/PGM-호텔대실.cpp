#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//10분 더해주는 function
string plusTen(string time){
    string hour(time.begin(),time.begin()+2); // 시간  추출
    string minute(time.begin()+3, time.begin()+5); // 분 추출
    
    int a = stoi(hour);
    int b = stoi(minute);
    
    b += 10; // 10분 더해주기
    if(b >= 60){ // 60분 넘으면 시간에 1 더해주고 분에 60 빼주기
        a += 1;
        b -= 60;
    }
    hour = to_string(a);
    minute = to_string(b);

    // 한 자리 수이면 앞에 0 붙여주기
    if(hour.size() == 1) hour = '0' + hour; 
    if(minute.size() == 1) minute = '0' + minute; 

    //format 맞춰주기
    return hour+':'+minute;
}

int solution(vector<vector<string>> book_time) {
    sort(book_time.begin(),book_time.end()); // 시간 빠른 순으로 정렬
    priority_queue<string, vector<string>, greater<string>> pq; // 우선 순위 큐 만들어 주기
    pq.push(plusTen(book_time[0][1])); // 제일 빠른 시간의 끝 시간+10분 넣어주기
    for(int i = 1 ; i < book_time.size();i++){ 
        if(book_time[i][0] >= pq.top()) // 제일 빨리 끝나는 시간보다 늦게 시작하면 같은 객실 쓰기
            pq.pop();
        pq.push(plusTen(book_time[i][1])); 
    }
 
    return pq.size(); // 객실 수 반환
}
