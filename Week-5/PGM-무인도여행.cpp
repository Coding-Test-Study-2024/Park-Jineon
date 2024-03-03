#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> map;
vector<int> answer;

int find(int x, int y){
    if('1' <= map[y][x] && map[y][x] <= '9'){ //숫자면 상하좌우 탐색
        int now = map[y][x]-'0';
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        
        map[y][x] = 'X';
        if(map.size() > y+1 ) a = find(x,y+1);
        if(map[0].size() > x+1 ) b = find(x+1,y);
        if( -1 < y-1 ) c = find(x,y-1);
        if(-1 < x-1 ) d = find(x-1,y);
        
        return now+a+b+c+d; //현재 위치 숫자와 상하좌우 숫자 더한 값 return
    }else{ //X면 return 0
        return 0;
    }
    
    
}

vector<int> solution(vector<string> maps) {
    map = maps;
    
    for(int y = 0 ; y < map.size(); y++){
        for(int x = 0 ; x < map[0].size(); x++){
            if('1' <= map[y][x] && map[y][x] <= '9'){
                answer.push_back(find(x,y)); // 숫자 있는 곳부터 탐색 시작
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer.size() > 0 ? answer : vector<int>{-1};
}
