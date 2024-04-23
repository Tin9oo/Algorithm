#include <iostream>
#include <string>
using namespace std;

/*
    슬라이딩 윈도우
*/

#define LOG false

string s;
int a = 0;

int ans = 1000;

void solution() {
    for(int i = 0; i < s.length(); i++) {
        int cnt = 0;
        for(int j = i; j < i + a; j++) {
            if(s[j % s.size()] == 'b') cnt ++;
        }
        ans = min(ans, cnt);
        if(LOG) cout << "from " << i << "-th idx : ans = " << ans << ", cnt = " << cnt << endl;
    }
}

int main() {
    cin >> s;
    for(auto c: s) if(c == 'a') a++;
    if(LOG) cout << "a = " << a << endl;

    solution();

    cout << ans;

    return 0;
}