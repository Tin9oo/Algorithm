#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    map<string, pair<int, int>> m;
    m["1"]={0, 0}; m["2"]={0, 1}; m["3"]={0, 2};
    m["4"]={1, 0}; m["5"]={1, 1}; m["6"]={1, 2};
    m["7"]={2, 0}; m["8"]={2, 1}; m["9"]={2, 2};
    m["*"]={3, 0}; m["0"]={3, 1}; m["#"]={3, 2};
    
    int n;
    string cur_l="*", cur_r="#"; // 위치를 높이로 저장. (123:0, 456:1, 789:2, *0#: 3)
    
    for(int i = 0; i < numbers.size(); ++i) {
        string n = to_string(numbers[i]);
        
        // cout << "Current num: " << n << endl;
        // cout << "Current left hand pos: " << cur_l << endl;
        // cout << "Current right hand pos: " << cur_r << endl;
        
        if(n=="1" || n=="4" || n=="7") {
            answer+="L";
            cur_l=n;
        }
        else if(n=="3" || n=="6" || n=="9") {
            answer+="R";
            cur_r=n;
        }
        else {
            int a=abs(m[n].first-m[cur_l].first)+abs(m[n].second-m[cur_l].second);
            int b=abs(m[n].first-m[cur_r].first)+abs(m[n].second-m[cur_r].second);
            
            // cout << "Left distance: " << a << endl;
            // cout << "Right distance: " << b << endl;

            if(a < b) {
                answer+="L";
                cur_l=n;
            }
            else if(a > b) {
                answer+="R";
                cur_r=n;
            }
            else if(a==b) {
                answer+=toupper(hand[0]);
                if(toupper(hand[0])=='L') {
                    cur_l=n;
                }
                else if(toupper(hand[0])=='R') {
                    cur_r=n;
                }
            }
        }
    }
    
    return answer;
}