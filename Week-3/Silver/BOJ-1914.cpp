#include <iostream>
using namespace std;

//하노이 탑
void hanoi(int start, int end, int middle, int n){
    if(n == 0) return;
    hanoi(start, middle, end, n-1); //n-1개 시작에서 중간으로 옮기는 단계
    cout << start << ' ' << end << '\n';
    hanoi(middle, end, start, n-1); //n-1개 중간에서 목표로 옮기는 단계
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    long long cnt = 1;
    for(int i = 0; i < n; i++) cnt*=2; // 옮기는 횟수 = (탑 개수)**2 - 1
    cout << cnt -1 << endl;
    hanoi(1,3,2,n);
}
