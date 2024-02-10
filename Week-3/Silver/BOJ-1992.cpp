#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> video;

string compress(int x, int y, int n) {
    if (n == 1) {
        string q;
        q+=video[y][x];
        return q;
    }
    

    string a = compress(x, y, n / 2);
    string b = compress(x, y+n / 2, n / 2);
    string c = compress(x+n / 2, y, n / 2);
    string d = compress(x+n / 2, y+n / 2, n / 2);
    
    if (a == b and b == c and c == d) {
        return  a;
    }
    else {
        return "(" + a + b + c + d + ')';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    string a;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m;
        a = to_string(m);
        for(int j = a.size(); j < n; j++) a = "0"+a;
        video.push_back(a);
    }

    cout << compress(0, 0, n) << endl;

    return 0;
}
