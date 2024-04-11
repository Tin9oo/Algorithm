#include <iostream>
#include <deque>

using namespace std;

#define LOG false

// 1시간 25분 실패

int n, k;
deque<int> conv1; // 2N의 크기를 유지하며 계속 회전시킨다.
deque<int> conv2;
deque<int> robot;   // 로봇 매번 삽입하고 값은 로봇의 위치를 저장한다.
                    // 삽입되었는지 여부를 로봇의 위치에 저장하는게 더 좋을수도 있었겠다.

void input() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        conv1.push_back(a);
        robot.push_back(0);
    }
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        conv2.push_front(a); // 한줄로 입력받다보니 push_front()로 받아야한다.
    }
}

void print_conv() {
    cout << "print_conv();" << endl;
    for(int i = 0; i < n; i++) {
        int c = conv1[i];
        cout << c << "(" << robot[i] << ")" << "\t";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        int c = conv2[i];
        cout << c << "\t";
    }
    cout << endl << endl;
}

void turn_conv() {
    if(LOG) cout << "turn_conv();" << endl;
    conv1.push_front(conv2.front());
    conv2.push_back(conv1.back());
    conv1.pop_back(); conv2.pop_front();

    robot.push_front(0);
    robot.pop_back();
    if(robot.back() == 1) robot[robot.size()-1] = 0;
}

bool can_move(int idx) {
    if(robot[idx+1] == 0 && conv1[idx+1] > 0) {
        return true;
    }

    return false;
}

void move_robot() {
    if(LOG) cout << "move_robot();" << endl;
    for(int i = robot.size()-2; i >= 0; i--) {
        if(robot[i] == 1 && can_move(i)) {
            if(LOG) cout << "robot[" << i << "] can move!!" << endl;
            robot[i+1] = 1; robot[i] = 0; // 이동하면 지워줘야지ㅎㅎ
            conv1[i+1]--;
            if(robot[i+1] == n-1) {
                robot[i+1] = 0;
            }
        }
    }
}

bool check_push() {
    if(conv1[0] == 0) return false;
    // if(!robot.empty() && robot.front() == 0) return false; // robot 없는 경우 예외처리
    if(robot.front() == 1) return false;
    return true;
}

void push_robot() {
    if(LOG) cout << "push_robot();" << endl;
    if(check_push()) {
        robot[0] = 1;
        conv1[0]--;
    }
}
bool check_k() {
    if(LOG) cout << "check_k();" << endl;
    int cnt = 0;

    for(auto c1: conv1) {
        if(c1 == 0) cnt++;
    }
    for(auto c2: conv2) {
        if(c2 == 0) cnt++;
    }

    if(cnt < k) return false;
    return true;
}

void solution() {
    int lvl = 1;
    do {
        if(LOG) cout << "=====" << endl;
        if(LOG) cout << "lvl: ";
        if(LOG) cout << lvl << endl;
        if(LOG) print_conv();
        turn_conv();
        if(LOG) print_conv();
        move_robot();
        if(LOG) print_conv();
        push_robot();
        if(LOG) print_conv();
        if(check_k()) {
            break;
        }
    } while(lvl++);
    cout << lvl;
}

void solve() {
    input();
    solution();
}

int main() {
    solve();
    return 0;
}