#include <iostream>
#include <queue> // priority_queue
#include <vector>
#include <algorithm>

using namespace std;

//Queue는 먼저 들어오는 데이터가 먼저 나가는 FIFO형식의 자료구조이다.

//우선순위 큐는 먼저 들어오는 데이터가 아니라, 우선순위가 높은 데이터가 먼저 나가는 형태의 자료구조이다.
//어떤 원소가 push된다면 주어진 순위에 맞춰서 Queue가 정렬되고,
//pop은 정렬된 Queue의 앞에서 이루어진다.

//priority_queue는 자료구조 heap으로 구현되었기 때문에,
//특정 원소를 push해서 생기는 정렬 과정은 O(logN)만에 이루어진다.

vector<pair<int, int> > class_time; // 수업시간 목록
priority_queue< int, vector<int>, greater<int> > pq;

//int형 변수를 cmp 우선순위에 따라 정렬하는 pq라는 이름의 priority_queue를 선언한다.
//오름차순으로 우선순위 큐를 정렬한다. 가장 작은 값이 우선순위가 되는 큐

int greedy(int class_count){
    pq.push(class_time[0].second); // 첫 번째 수업의 종료 시간을 pq에 push한다.
    for(int i=1; i<class_count; i++){
        pq.push(class_time[i].second); // i 번째 수업의 종료 시간을 pq에 push한다.
        if (pq.top() <= class_time[i].first){ //top의 종료 시간보다 i 번재 수업이 늦게 시작한다면, 같은 강의식에서 진행 가능
            pq.pop(); //기존의 top은 제거
        }
    }

    return pq.size(); //필요한 강의실 개수
}

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; ++i){

        int start_time, end_time;
        cin >> start_time >> end_time;

        class_time.push_back(make_pair(start_time, end_time));
    }
    
    //시작 시간 기준으로 수업 정렬
    sort(class_time.begin(), class_time.end());
    cout << greedy(n) << endl;

}
