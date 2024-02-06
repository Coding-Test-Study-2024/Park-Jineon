#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    string S, T;
    cin >> S >> T;
  
    //거꾸로 적용하기
    while(S.size() != T.size()){ // 사이즈 같을 때 멈춤
        if(T[T.size()-1] == 'B'){ // 맨 마지막이 B일 때
            T.erase(T.end()-1,T.end()); // 맨 마지막 삭제
            reverse(T.begin(),T.end()); // 뒤집기
        }else{ // 맨 마지막이 A일 때
            T.erase(T.end()-1,T.end()); // 맨 마지막 삭제
        }
    }
    
    int result = T==S ? 1 : 0;
    cout << result << endl;

}
