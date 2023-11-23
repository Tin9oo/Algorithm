#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<string, int> m;
    
    m["R"]=0;
    m["T"]=0;
    m["C"]=0;
    m["F"]=0;
    m["J"]=0;
    m["M"]=0;
    m["A"]=0;
    m["N"]=0;
    
    for(int i = 0; i < survey.size(); ++i) {
        string sv = survey[i];
        int score = choices[i]-4;
        if(score==0) {
            continue;
        }
        else if(score<0) {
            m[string(1, sv[0])] += abs(score);
        }
        else if(score>0) {
            m[string(1, sv[1])] += abs(score);
        }
    }
    
    // for(map<string, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
    //     cout << itr->first << ": " << itr->second << endl;
    // }
    
    if(m["R"] >= m["T"]) {
        answer += "R";
    }
    else {
        answer += "T";
    }
    if(m["C"] >= m["F"]) {
        answer += "C";
    }
    else {
        answer += "F";
    }
    if(m["J"] >= m["M"]) {
        answer += "J";
    }
    else {
        answer += "M";
    }
    if(m["A"] >= m["N"]) {
        answer += "A";
    }
    else {
        answer += "N";
    }
    
    return answer;
}