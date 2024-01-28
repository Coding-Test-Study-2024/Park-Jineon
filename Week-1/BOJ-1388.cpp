#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int w , h; // w = 가로, h = 세로
    int cnt = 0; // cnt = 나무 판자 개수
    bool same = false; // same = 같은 판자인지 여부
    
    // 입력값 받기
    cin >> h >> w;
    string str;
    vector<string> arr;
    for(int i = 0; i < h; i++){
        cin >> str;
        arr.push_back(str);
    }
    
    // 가로 판자 개수 세기
    for(int i = 0; i < h; i++){
        same = false;
        for(int j = 0; j < w; j++){
            if(arr[i][j]=='-' and not same){
                cnt++;
                same = true;
            }else if(arr[i][j]=='|'){
                same = false;
            }
        }
    }
    
    // 세로 판자 개수 세기
    for(int i = 0; i < w; i++){
        same = false;
        for(int j = 0; j < h; j++){
            if(arr[j][i]=='|' and not same){
                cnt++;
                same = true;
            }else if(arr[j][i]=='-'){
                same = false;
            }else{
                same = true;
            }
        }
    }
    
    // 출력
    cout << cnt << endl;
    return 0;
}
