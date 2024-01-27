#include <iostream> // 입출력
#include <algorithm> // sort()
using namespace std;

int main(){
    // 변수 선언
    int n , mem; // n = 정렬할 숫자 갯수, mem = 회원 수
    cin >> n;
    int num[n] = {0}; // num = 정렬할 숫자 배열
    
    // 입력값 받기
    for(int i = 0; i < n; i++) cin >> num[i];
    cin >> mem;
    
    // 각 사람당 앞에서부터 차례대로 (n/mem)개의 숫자 정렬
    for(int i = 0; i < mem; i++) sort(num+i*(n/mem),num+(i+1)*(n/mem));
    
    // 출력
    for(int i = 0; i < n; i++) cout << num[i] <<' ';
    return 0;
}
