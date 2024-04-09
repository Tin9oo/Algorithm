#include <iostream>
#include <deque>

using namespace std;

#define LOG false

// 실패(1시간)
// 방향 자체는 잘 잡고 가고있었는데, 시작 기어로부터 회전 방향 결정할 때 한방향으로 이동하며 판단해야하는 부분을 해결하지 못하고있었다.
// 기존에 dfs로 구현하려 하니까 양방향으로 모두 찾아가는데, 두 방향에 각각 함수를 구현하면 dfs로 구현해도 한 방향으로만 탐색한다.

#define GEAR_NUMBER 4
#define COG_NUMBER 8
#define TURN_MAX 100

deque<int> gear_arr[GEAR_NUMBER];
int k;
pair<int, int> turn_arr[TURN_MAX] = {};
int gear_turn_arr[GEAR_NUMBER] = {};

int answer = 0;

void input() {
    if(LOG) cout << "input()" << endl;

    string gear; 
    for(int i = 0; i < GEAR_NUMBER; i++) { // 하나의 문자열로 입력이 들어오니까 하나씩 받으면 안된다.
        cin >> gear;
        for(int j = 0; j < COG_NUMBER; j++) {
            gear_arr[i].push_back(gear[j]-'0');
        }
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b; // 바퀴 번호가 1부터 시작이다ㅋㅋ
        turn_arr[i].first = a-1;
        turn_arr[i].second = b; // 얘는 또 -1 하면 안되지 임마ㅋㅋ
    }
}

void init() {
    if(LOG) cout << "init()" << endl;
    for(int i = 0; i < GEAR_NUMBER; i++) {
        gear_turn_arr[i] = 0;
    }
}

void turn(int idx, int clockwise) {
    if(LOG) cout << "turn(idx=" << idx << ", clockwise=" << clockwise << ")" << endl;
    if(clockwise == 1) {
        gear_arr[idx].push_front(gear_arr[idx].back());
        gear_arr[idx].pop_back();
    }
    else if(clockwise == -1) {
        gear_arr[idx].push_back(gear_arr[idx].front());
        gear_arr[idx].pop_front();
    }
}

void check_left(int idx, int clockwise) {
    if(idx >= 0) {
        if(gear_arr[idx][2] != gear_arr[idx+1][6]) {
            gear_turn_arr[idx] = clockwise * -1;
            check_left(idx-1, clockwise * -1);
        }
    }
}

void check_right(int idx, int clockwise) {
    if(idx < GEAR_NUMBER) {
        if(gear_arr[idx-1][2] != gear_arr[idx][6]) {
            gear_turn_arr[idx] = clockwise * -1;
            check_right(idx+1, clockwise * -1);
        }
    }
}

void check_turn(int idx, int clockwise) {
    if(LOG) cout << "check_turn()" << endl;
    gear_turn_arr[idx] = clockwise;
    check_left(idx-1, clockwise);
    check_right(idx+1, clockwise);
    if(LOG) {
        for(int i = 0; i < GEAR_NUMBER; i++) {
            cout << gear_turn_arr[i] << " ";
        }
        cout << endl;
    }
}

void score() {
    if(LOG) cout << "score()" << endl;
    int sc = 1;
    for(int i = 0; i < GEAR_NUMBER; i++) {
        if(LOG) cout << gear_arr[i].front();
        if(gear_arr[i].front()) answer += sc;
        sc *=2;
    }
    if(LOG) cout << endl;
}

void print() {
    for(int i = 0; i < GEAR_NUMBER; i++) {
        for(int j = 0; j < COG_NUMBER; j++) {
            cout << gear_arr[i][j] << " ";
        }
        cout << endl;
    }
}

void solution(){
    for(int i = 0; i < k; i++) {
        if(LOG) cout << "solution(i=" << i << ")" << endl;
        if(LOG) print();
        init();
        check_turn(turn_arr[i].first, turn_arr[i].second);
        for(int i = 0; i < GEAR_NUMBER; i++) {
            turn(i, gear_turn_arr[i]);
        }
    }
    score();
    cout << answer;
}

void solve() {
    input();
    solution();
}

int main() {
    solve();

    return 0;
}