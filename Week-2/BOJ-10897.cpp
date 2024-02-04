#include <iostream>
using namespace std;


int main(){
    int n, m;
    unsigned long long first = 1; //자식 세대 첫 번째 노드 번호
    unsigned long long cnt = 1; //자식 세대 노드 개수
    unsigned long long now = 1; //자식 노드 중  첫 번째 노드 번호
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        cin >> m;
        now = (now%1000000007+m%1000000007-1)%1000000007; // 출력할 번호 계산
        cout << now%1000000007 << endl; //출력 , 다음 세대로 이동
        now = (now%1000000007-first%1000000007)*(i+1)%1000000007; // 자식 노드 중 첫 번째 노드 번호 계산 과정
        
        first = (first%1000000007 + cnt%1000000007)%1000000007; //다음 세대 첫 번째 노드 번호 계산
        now = (first%1000000007 + now%1000000007)%1000000007;  // 자식 노드 중 첫 번째 노드 번호
        cnt = (cnt%1000000007*(i+1))%1000000007; //다음 세대 노드 개수 계산
    }
    
    return 0 ;
}
