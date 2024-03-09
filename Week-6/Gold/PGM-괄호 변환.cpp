#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//올바른 문자열인지 확인
bool isRight(string p){
    int stack = 0;
    for(int i = 0; i < p.size(); i++){
        if(p[i] == '(') stack++;
        else{
            if(stack == 0) return false;
            else stack--;
        }
    }
    return true;
}


// 1번
string first(string p){
    if(p == "") return "";
    else{ //2번
        int left = 0;
        int right = 0;
        int i = 0;
        for( ;i < p.size(); i++){
            if(p[i] == '(') left++;
            else right++;

            if(left == right) break;
        }

        string u = p.substr(0,i+1);
        string v = p.substr(i+1,p.size()-i-1);
        
        cout << u << ' ' << v << endl;
        // 3번
        if(isRight(u)){
            return u + first(v); // 3-1번
        }//4번
        else{
            string newU = "";
            for(int i = 1; i < u.size()-1; i++){
                if(u[i] == '(') newU += ')';
                else newU += '(';
            }
            return '(' + first(v) + ')' + newU;
        }
    };
}



string solution(string p) {
    return first(p);
}
