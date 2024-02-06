#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<int, int> > class_time;
priority_queue< int, vector<int>, greater<int> > pq_less;

int greedy(int class_count){
    pq_less.push(class_time[0].second);
    for(int i=1; i<class_count; i++){
        pq_less.push(class_time[i].second);
        if (pq_less.top() <= class_time[i].first){
            pq_less.pop();
        }
    }
    return pq_less.size();
}

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; ++i){

        int start_time, end_time;
        cin >> start_time >> end_time;

        class_time.push_back(make_pair(start_time, end_time));
    }
    
    sort(class_time.begin(), class_time.end());
    cout << greedy(n) << endl;

}
