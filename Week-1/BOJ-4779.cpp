#include <iostream>
#include <string>

using namespace std;

int main() {
    // 변수 선언
    int N;
    string str, blank;

    // 입력값 받기
    while(cin >> N){
      
        // 출력값은 str + 공백 + str 의 반복으로 이루어져 있다.
        str = "-";
        for(int i = 0; i < N; i++){
            blank = "";  
            for(int j = 0; j < str.size(); j++) blank += " "; // 각 공백은 앞 str.size()만큼 있다
            str = str+blank+str;
        }

        //출력
        cout << str <<endl;
    }
    return 0;
}
