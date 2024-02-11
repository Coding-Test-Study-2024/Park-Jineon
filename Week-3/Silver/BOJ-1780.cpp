#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper; // 종이 입력받을 vector
int cnt[4]; //각 숫자 적힌 종이 갯수 + 허수 받을 값 1개

int cut(int x, int y, int n){
  
    if(n==1) return paper[y][x]; // 길이 1일 때 반환

    // 9분할
    vector<int> a;
    a.push_back(cut(x, y ,n/3));
    a.push_back(cut(x+n/3, y ,n/3));
    a.push_back(cut(x+n/3*2, y ,n/3));
    a.push_back(cut(x, y+n/3 ,n/3));
    a.push_back(cut(x+n/3, y+n/3 ,n/3));
    a.push_back(cut(x+n/3*2, y+n/3 ,n/3));
    a.push_back(cut(x, y+n/3*2, n/3));
    a.push_back(cut(x+n/3, y+n/3*2,n/3));
    a.push_back(cut(x+n/3*2, y+n/3*2, n/3));

    // 9개 다 같은지 확인
    bool same = true;
    
    for(int i = 1; i < 9; i++){
        if(a[i]!=a[i-1]){
            same= false;
            break;
        }
    }

    
    if(!same){ //9개 다 같지 않으면 1개씩 값 올려주기
        for(int i = 0; i < 9; i++)
            cnt[a[i]+1]++;
        return 2; // 더 이상 세지 않는 종이 2 반환
    }else{
        return a[0]; // 9개 결과값 다 같으면 a[0] 반환
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력받기
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        vector<int> a;
        for(int j = 0; j < n; j++){
            cin >> m;
            a.push_back(m);
        }
        paper.push_back(a);
    }
    int a = cut(0,0,n);

    // 마지막 반환된 값 count하기
    cnt[a+1]++;

    //출력
    cout<< cnt[0] << endl << cnt[1] << endl << cnt[2] << endl;
    return 0;
}
