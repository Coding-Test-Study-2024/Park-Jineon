#include <string>
#include <vector>
#include <iostream>
using namespace std;

//악보 중 # 변환
string convertInfo(string m){ 
    while(m.find("C#") != string::npos) m.replace(m.find("C#"),2,"c");
    while(m.find("D#") != string::npos) m.replace(m.find("D#"),2,"d");
    while(m.find("F#") != string::npos) m.replace(m.find("F#"),2,"f");
    while(m.find("G#") != string::npos) m.replace(m.find("G#"),2,"g");
    while(m.find("A#") != string::npos) m.replace(m.find("A#"),2,"a");
    while(m.find("B#") != string::npos) m.replace(m.find("B#"),2,"b");
    return m;
}

string solution(string m, vector<string> musicinfos) {
    vector<string> answer;
    vector<vector<string>> info;
    vector<vector<string>> candidate;
    
    m = convertInfo(m); //# 변환

    //입력값 변환하기
    for(int i = 0; i < musicinfos.size(); i++){
      
        info.push_back(vector<string>{});
        int start = 0;
        int now = 0;
      
        do{ // 쉼표에 맞춰서 분할
            now = musicinfos[i].find(',', start);
            info[i].push_back(musicinfos[i].substr(start,now-start));
            start = now+1;
        }
        while(musicinfos[i].find(',', start) != string::npos);

        //시간 계산
        int hour = stoi(info[i][1].substr(0,2)) - stoi(info[i][0].substr(0,2));
        int minute = stoi(info[i][1].substr(3,2)) - stoi(info[i][0].substr(3,2));
        int time = hour*60+minute; 
      
        string a = "";
        string b = musicinfos[i].substr(start,now-start);
        b = convertInfo(b); // # 변환
      
        for(int j = 0; a.size() < time ; j++) a += b; //시간에 맞춰 악보 재구성
        info[i].push_back(a.substr(0,time)); // 악보 넣기
        info[i].push_back(to_string(time)); // 시간 넣기
    }

    // 해당 되는 곡 찾기
    for(int i = 0; i < info.size(); i++){
        if(info[i][3].find(m) != string::npos){ // 해당 되는 곡 candidate에 넣어주기
            candidate.push_back(vector<string>{});
            candidate[candidate.size()-1].push_back(info[i][2]); // 곡 명 
            candidate[candidate.size()-1].push_back(info[i][4]); // 곡 시간
        }
    }

    // return 하기
    if(candidate.size() > 1){
        int max = 0;
        for(int i = 0 ; i < candidate.size(); i++){ // 해당 되는 곡 여러 개면 조건에 맞춰서 return
            if(max < stoi(candidate[i][1])){ // 재생시간 가장 긴 곡 찾기
                answer.clear();
                answer.push_back(candidate[i][0]);
                max = stoi(candidate[i][1]);
            }else if(max == stoi(candidate[i][1])) answer.push_back(candidate[i][0]);
        }
        return answer[0]; //첫 번째 입력된 곡 return
    }else if(candidate.size() == 1){
        return candidate[0][0];
    }else{
        return "(None)";
    }
}
