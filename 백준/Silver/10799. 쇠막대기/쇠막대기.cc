#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 개요 =====

// 접근 =====
// 괄호 열리면 바 개수 늘리고 하는 방식은 어때?
// ()(((()())(())()))(())
// |(((||)(|)|))(|)

// 괄호가 바로 닫혔다는 사실을 확인할 수 있어야한다.

#define LOG false

string s;

int answer = 0;

void input() {
    cin >> s;
}

void cut() {
    int num_bar = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            num_bar++;
        }
        else if(i > 0 && s[i-1] == '(' && s[i] == ')') { // 자르면 해당 겹친 길이만큼 막대가 생긴다.
            answer += --num_bar;
            if(LOG) cout << i << "-th cut() num_bar: " << num_bar << endl;
        }
        else if(s[i] == ')') { // 괄호가 닫히면 끝에도달한 막대가 한조각 남는다.
            num_bar--;
            answer++;
        }
    }
}

void solution() {
    cut();
}

void output() {
    cout << answer;
}

void solve() {
    input();
    solution();
    output();
}

int main() {
    solve();
    return 0;
}