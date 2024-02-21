#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<char,int> cnt; //알파벳 별 나오는 자릿수 저장
    int n;
    string a;
    
    int answer = 0;
    cin >> n;
    
    for(int i = 0 ; i < n; i++){
        cin >> a;
        int digit = 1;
        for(int j = a.size()-1 ; j > -1 ; j--){ //각 string의 1의 자리부터 알파벳 별로 digit 저장
            if(cnt[a[j]] > 0){
                cnt[a[j]]+= digit;
            }else{
                cnt[a[j]] = digit;
            }
            digit *= 10;
        }
    }
    
    
    vector<int> result;
    
    for(auto it = cnt.begin(); it != cnt.end(); it++)
        result.push_back(it->second);

    sort(result.begin(),result.end(),greater<int>()); // 큰 순서대로 정렬
    int m = 9;
    for(int i = 0; i < result.size(); i++){ // 큰 순서대로 큰 숫자 부여
        answer += m*result[i];
        m--;
    }
    
    cout << answer << endl;
    return 0;
}
