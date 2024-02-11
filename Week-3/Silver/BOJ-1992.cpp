#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> video; //list 입력 받을 vector

string compress(int x, int y, int n) {
    if (n == 1) { // 길이가 1일 때 반환
        string q;
        q+=video[y][x];
        return q;
    }
    
    //차례대로 4분할
    string a = compress(x, y, n / 2);
    string b = compress(x+n / 2, y, n / 2);
    string c = compress(x, y+n / 2, n / 2);
    string d = compress(x+n / 2, y+n / 2, n / 2);
    
    if (a.size()==1 and a == b and b == c and c == d) return  a; // 4분할 결과 값 각각이 한자리 수 이고 다 같으면 압축 가능
    else return "(" + a + b + c + d + ')'; // 다르면 나열

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string m;
    cin >> n;

    // 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> m;
        video.push_back(m);
    }

    cout << compress(0, 0, n) << endl;

    return 0;
}
