#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

#define debug 0

string fn_enter(string rec, unordered_map<string, string> *name_manage) {
    if(debug) cout << "===== fn enter =====" << endl;
    vector<string> vec;

    for(int i = 0; i < 2; ++i) {
        if(rec.find(" ")!=string::npos) {
            vec.push_back(rec.substr(0, rec.find(" ")));
            rec = rec.substr(rec.find(" ")+1);
        }
        if(debug) cout << vec[i] << " ";
    }

    vec.push_back(rec);
    if(debug) cout << vec[2] << " " << endl;
    
    auto it = (*name_manage).find(vec[1]);
    if(it!=(*name_manage).end()) {
        it->second = vec[2];
    }
    else {
        (*name_manage)[vec[1]] = vec[2];
    }

    return vec[1];
}

string fn_leave(string rec) {
    if(debug) cout << "===== fn leave =====" << endl;
    vector<string> vec;

    for(int i = 0; i < 1; ++i) {
        if(rec.find(" ")!=string::npos) {
            vec.push_back(rec.substr(0, rec.find(" ")));
            rec = rec.substr(rec.find(" ")+1);
        }
        if(debug) cout << vec[i] << " ";
    }

    vec.push_back(rec);
    if(debug) cout << vec[1] << " " << endl;

    return vec[1];
}

void fn_change(string rec, unordered_map<string, string> *name_manage) {
    if(debug) cout << "===== fn change =====" << endl;
    vector<string> vec;

    for(int i = 0; i < 2; ++i) {
        if(rec.find(" ")!=string::npos) {
            vec.push_back(rec.substr(0, rec.find(" ")));
            rec = rec.substr(rec.find(" ")+1);
        }
        if(debug) cout << vec[i] << " ";
    }

    vec.push_back(rec);
    if(debug) cout << vec[2] << " " << endl;
    
    auto it = (*name_manage).find(vec[1]);
    if(it!=(*name_manage).end()) {
        it->second = vec[2];
    }
    else {
        (*name_manage)[vec[1]] = vec[2];
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<string> log;
    unordered_map<string, string> name_manage;
    string str;

    for(int i = 0; i < record.size(); ++i) {
        str = "";
        
        if(record[i][0]=='E') {
            str = fn_enter(record[i], &name_manage) + "님이 들어왔습니다.";
            log.push_back(str);
        }
        else if(record[i][0]=='L') {
            str = fn_leave(record[i]) + "님이 나갔습니다.";
            log.push_back(str);
        }
        else if(record[i][0]=='C') {
            fn_change(record[i], &name_manage);
        }
    }
    
    if(debug) {
        for(const auto& pair : name_manage) {
            cout << pair.first << ", " << pair.second << endl;
        }
    }
    
    for(int i = 0; i < log.size(); ++i) {
        str = log[i].substr(0, log[i].find("님"));
        
        log[i].erase(0, log[i].find("님"));
        log[i] = name_manage[str] + log[i];
        if(debug) cout << str << endl;
    }
    
    answer = log;

    return answer;
}