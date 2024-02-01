#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> makeSubArray(vector<vector<int>>arr, int x1, int x2, int y1, int y2){
    vector<vector<int>> temp;
    
    for(int i = y1; i < y2; i++){
        vector<int> subTemp;
        for(int j = x1; j < x2; j++){
            subTemp.push_back(arr[i][j]);
        }
        temp.push_back(subTemp);
    }
    
    return temp;
}


int pickOne(vector<vector<int>> arr){
    if(arr.size() == 1) return arr[0][0];
    
    
    int a = pickOne(makeSubArray(arr, 0, arr.size()/2, 0, arr.size()/2));
    int b = pickOne(makeSubArray(arr, 0, arr.size()/2, arr.size()/2, arr.size()));
    int c = pickOne(makeSubArray(arr, arr.size()/2, arr.size(), 0, arr.size()/2));
    int d = pickOne(makeSubArray(arr, arr.size()/2, arr.size(), arr.size()/2, arr.size()));
    
    
    vector<int> temp = {a, b, c, d};
    sort(temp.begin(), temp.end());
    return temp[1];
}



int main() {
    int n, m;
    vector<vector<int>> list;
    cin >> n;
    
    for(int i=0; i < n; i++){
        vector<int> a;
        for(int j=0; j < n; j++){
            cin >> m;
            a.push_back(m);
        }
        list.push_back(a);
    }
 
    
    cout << pickOne(list);

    return 0;
}
