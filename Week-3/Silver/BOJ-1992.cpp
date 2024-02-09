#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<vector<int>> video;

string compress(int x, int y, int n) {
    if (n == 1) return to_string(video[y][x]);
    string a = compress(0, 0, n / 2);
    string b = compress(0, n / 2, n / 2);
    string c = compress(n / 2, 0, n / 2);
    string d = compress(n / 2, n / 2, n / 2);

    if (a == b and b == c and c == d) {
        return '(' + a + ')';
    }
    else {
        return '(' + a + b + c + d + ')';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<int> a;
        for (int j = 0; j < n; j++) {
            cin >> m;
            a.push_back(m);
        }
        video.push_back(a);
    }

    cout << compress(0, 0, n) << endl;

    return 0;
}
