#include <string>
#include <vector>
#include <stack>

using namespace std;

struct node {
    int n;
    int left;
    int right;
    node(int n, int l, int r) : n(n), left(l), right(r) {}
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
        
    vector<node> table;
    for(int i = 0; i < n; ++i) {
        table.push_back(node(i, i-1, i+1));
    }
    
    stack<node> hist;
    
    answer = string(n, 'O');
    
    int cursor = k;
    
    for(int i = 0; i < cmd.size(); ++i) {
        string c = cmd[i];
        if(c[0]=='U') {
            int cnt = stoi(c.substr(2));
            for(int j = 0; j < cnt; ++j) {
                cursor = table[cursor].left;
            }
        }
        else if(c[0]=='D') {
            int cnt = stoi(c.substr(2));
            for(int j = 0; j < cnt; ++j) {
                cursor = table[cursor].right;
            }
        }
        else if(c=="C") {
            hist.push(table[cursor]);
            
            int cur_left = table[cursor].left;
            int cur_right = table[cursor].right;
            
            if(cur_left!=-1) table[cur_left].right = cur_right;
            if(cur_right!=n) table[cur_right].left = cur_left;
            
            answer[cursor] = 'X';
            
            if(cur_right==n) cursor = cur_left;
            else cursor = cur_right;
        }
        else if(c=="Z") {
            node h = hist.top();
            hist.pop();
            
            int cur_left = h.left;
            int cur_right = h.right;
            
            if(cur_left!=-1) table[cur_left].right = h.n;
            if(cur_right!=n) table[cur_right].left = h.n;
            
            answer[h.n] = 'O';
        }
    }
    
    return answer;
}