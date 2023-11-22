#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> i, vector<int> j) {
    return i.size() < j.size();
}

void print_V(vector<vector<int>> V) {
    for(int i = 0; i < V.size(); ++i) {
        for(int j = 0; j < V[i].size(); ++j) {
            cout << V[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    return;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    set<int> unique_nums;
    vector<vector<int>> V;
    vector<int> v;
    
    string tmp;
    for(int i = 2; i < s.length()-1; ++i) {
        if(s[i]=='}') {
            v.push_back(stoi(tmp));
            tmp="";
            V.push_back(v);
            v.clear();
            i+=2;
            continue;
        }
        
        if(s[i]==',') {
            v.push_back(stoi(tmp));
            tmp="";
            continue;
        }
        
        tmp+=s[i];
    }
    
    // print_V(V);
    
    sort(V.begin(), V.end(), cmp);
    
    // print_V(V);
    
    for(int i = 0; i < V.size(); ++i) {
        for(int j = 0; j < V[i].size(); ++j) {
            bool can_insert=true;
            for(int k = 0; k < answer.size(); ++k) {
                if(answer[k]==V[i][j]) {
                    can_insert=false;
                    break;
                }
            }
            if(can_insert==true) {
                answer.push_back(V[i][j]);
            }
        }
    }
    
    return answer;
}