#include <iostream>
#include <vector>
using namespace std;

//변수 선언
vector<vector<bool>> list; // 0과 1로 이루어져있기 때문에 bool 가능
int white = 0; //흰 색종이
int blue = 0; //파란 색종이

int count(int x, int y, int n){
    bool std = list[y][x]; //첫 종이 색깔 기준점
    bool same = true; // 기준점과 같은 색깔인지 확인
    
    for(int i = y; i < y+n; i++){
        for(int j =x; j < x+n; j++){
            if(list[i][j] != std){ //기준점과 같은 색이 아니면 false로 바꾸고 for문 break
                same=false;
                break;
            }
        }
        if(not same) break; //기준점과 같은 색이 아니면 false로 바꾸고 for문 break
    }
    
    if(same){ //모두 기준점과 같은 색이면 기준점 색깔 변수 1 더해준다.
        if(std) blue++;
        else white++;
    }else{ //하나라도 기준점과 같은 색이 아니면 반으로 나눠서 다시 재귀함수 돈다.
        count(x, y, n/2);
        count(x, y+n/2, n/2);
        count(x+n/2, y, n/2);
        count(x+n/2, y+n/2, n/2);
    }
    
    return 0;
}


int main(){
    int n, m;
    cin >> n;
    //입력
    for(int i = 0; i < n; i++){
        vector<bool> a;
        for(int j =0; j < n; j++){
            cin >> m;
            a.push_back(m);
        }
        list.push_back(a);
    }
    
    count(0, 0, n);
    //출력
    cout<< white << endl << blue<< endl;
    
    return 0;
}
