#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//리스트 담을 전역변수 선언
vector<vector<int>> arr;

int pickOne(int x, int y, int n){
    if(n == 2){ //길이가 2일 때 2번째로 작은 값 반환
        int r[4] = {arr[y][x] , arr[y][x+1], arr[y+1][x], arr[y+1][x+1]};
        sort(r, r+4);
        return r[1];
    }

    //리스트 4분할로 나누기
    int a = pickOne(x, y, n/2);
    int b = pickOne(x, y+n/2, n/2);
    int c = pickOne(x+n/2, y, n/2);
    int d = pickOne(x+n/2, y+n/2, n/2);
    
    //2번째로 작은 값 반환
    int result[4] = {a, b, c, d};
    sort(result,result+4);
    return result[1];
}



int main() {
    int n, m;
    cin >> n;

    //1일 때 빠져나가기
    if(n==1){
        cin >> m;
        cout << m;
        return 0;
    }else{
        //입력 받기
        for(int i=0; i < n; i++){
            vector<int> a;
            for(int j=0; j < n; j++){
                cin >> m;
                a.push_back(m);
            }
            arr.push_back(a);
        }

        //재귀
        cout << pickOne(0,0,n)<<endl;
    }
    
    return 0;
}
