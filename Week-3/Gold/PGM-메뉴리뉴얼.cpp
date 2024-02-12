#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<char> m; // 메뉴 담는 vector
vector<string> comb; // 조합 담는 vector

//모든 조합 생성해내는 함수
void combination(int start, int n, string s){
    s = s + m[start];
    
    if(n==1){
        comb.push_back(s);
        return;
    }
    
    for(int i = start+1; i < m.size(); i++)
        combination(i,n-1, s);
}



vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    set<char> menu;

    //한 가지 메뉴 추출(중복 방지 위해 set 사용)
    for(int i = 0; i < orders.size(); i++)
        for(int j =0; j < orders[i].size(); j++)
            menu.insert(orders[i][j]);

    //set을 vector로 옮기기
    for(auto it = menu.begin(); it != menu.end(); it++)
        m.push_back(*it);

    //course의 수에 해당하는 모든 조합 만들기
    for(int j = 0; j < course.size(); j++)
        for(int i = 0 ; i < m.size(); i++)
            combination(i, course[j], "");


    
    int l = comb[0].size(); // course가 달라지는지 확인
    int M = 2; //최댓값 확인
    vector<string> a; //최댓갑에 해당하는 조합 담는 vector

    //모든 조합 순환
    for(int i = 0; i < comb.size(); i++){
        int cnt = 0; //해당 조합 가지고 있는 order의 개수
      
        for(int k = 0 ; k < orders.size(); k++){  //order 순환
            bool have = true; //해당 order이 해당 조합을 가지고 있는지 확인
          
            for(int j = 0; j < comb[i].size(); j++){
                if(orders[k].find(comb[i][j]) == string::npos){ //하나라도 없으면 break
                    have = false;
                    break;
                }
            }
          
            if(have) cnt++; // 가지고 있으면 cnt 올려주기
        }
        
        if(l != comb[i].size()){ // 새로운 course 수이면 이전 값 answer 배열로 옮기고 a값 초기화
            for(int x = 0 ; x < a.size(); x++){
                answer.push_back(a[x]);
            }
            a.clear();
            M = 2;
        }
        
        if(cnt == M) { // 최대값과 같으면 a에 추가
            a.push_back(comb[i]);
        }else if (cnt >= M){ //최대값보다 크면 a 초기화 후 추가
            a.clear();
            a.push_back(comb[i]);
            M = cnt;
        }
        
        l = comb[i].size(); // 현재 조합의 course 수 저장해주기
    }

    // 마지막 course에 해당하는 a를 answer로 이동
    for(int x = 0 ; x < a.size(); x++){
        answer.push_back(a[x]);
    }
  
    // 정렬
    sort(answer.begin(),answer.end());
    return answer;
}
