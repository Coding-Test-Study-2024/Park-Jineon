#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> locations;
vector<int> distances;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, location;

    cin >> n >> k;
    if(k >= n){ //집중국이 센서 수와 같거나 센서 수 보다 많은 경우 0 반환
        cout << 0; 
        return 0;
    }
    for(int i = 0; i < n; i++){
        cin >> location;
        locations.push_back(location); 
    }
    
    sort(locations.begin(),locations.end());
    for(int i = 1; i < (int)locations.size(); i++) //모든 간격 찾아주기
        distances.push_back(locations[i]-locations[i-1]);
    
    sort(distances.begin(),distances.end());
    cout << accumulate(distances.begin(),distances.end()-k+1,0); //모든 간격 중 가장 큰 k-1개의 간격 빼고 모두 더하기
    return 0;
}
