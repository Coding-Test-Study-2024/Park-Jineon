#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    priority_queue<int, vector<int>,greater<int>> pq; // 우선 순위 큐 사용

    cin >> n;
    for(int i = 0 ; i < n; i++){
        cin >> m;
        pq.push(m);
    }
    int answer = 0;
    while(pq.size() != 1){ //제일 작은 두 수 pop 후 더해서 다시 넣어주는 거 반복
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        answer += a+b; // 전체 a+b (전체 비교 횟수) 더해주기
        pq.push(a+b);
    }
    cout << answer << endl;
    return 0;
}
