#include <iostream>
using namespace std;

// 0은 3, 2, 1 ,0 순으로 큰 점수 획득
// 1은 2, 3, 0, 1 순으로 큰 점수 획득
// 2는 1, 0, 3, 2 순으로 큰 점수 획득
// 3은 0, 1, 2, 3 순으로 큰 점수 획득

int arr[4]={0};
int result = 0;

int calculate(int point, int end, int plus, int pair){
    int cnt;
    
    for(int i = 0; i < end; i+=plus){
        cnt = min(arr[i],arr[abs(i+pair)]); // 선물 쌍 개수 확인
        result += point*cnt; // 만족도 계산
        arr[i] -= cnt; // 개수 차감
        arr[abs(i+pair)] -= cnt; // 개수 차감
    }
    
    return result;
}

int main(){
    int N, m;
    cin >> N;
    
    // 가격별 선물 개수 입력
    for(int i = 0; i < N; i++){
        cin >> m;
        arr[m]++;
    }
    
    calculate(3, 2, 1, -3); // 3점 확인
    calculate(2, 2, 1, 2); // 2점 확인
    calculate(1, 3, 2, 1); // 1점 확인
    
    cout << result;
    return 0 ;
}
