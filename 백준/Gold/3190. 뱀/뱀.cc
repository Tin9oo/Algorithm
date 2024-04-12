#include <iostream>
#include <queue>

using namespace std;

#define LOG false

// 개요 =====
// 'Dummy'라는 도스 게임을 차용한다.
// 뱀이 기어다닌다.
// NxN 정사각 보드, 일부 칸에 사과 있음.
// 보드의 끝에 벽이 있다.
// 뱀은 맨위 맨좌측에 위치, 길이는 1, 방향은 오른쪽을 본다.
// 사과 인덱스는 맨 좌측 상단이 1,1이다.
// 사과 위치는 다른 사과나 뱀과 겹치지 않는다.
// 뱀의 방향 전환 횟수 : L
// 방향 전환 정보는 정수 X와 문자 C로 이루어졌다. 게임 시작시간으로부터 X초 끝난 후 왼쪽(L) 혹은 오른쪽(D)로 90도 방향을 회전시킨다.
// 방향전환 정보는 X가 증가하는 순으로 주어진다.

// 매 초마다 이동하며 다음 규칙을 따른다.
// 1. 머리를 늘려 머리를 다음칸에 위치시킨다.
// 2. 벽이나 자신의 몸과 부딪히면 게임 끝
// 3. 이동한 칸에 사과가 있다면, 사과 없애고 꼬리는 그대로있다.
// 4. 이동한 칸에 사과가 없다면, 몸길이 줄여서 꼬리 칸을 비운다. -> 몸길이는 그대로

// 사과의 위치와 뱀 이동경로가 주어지면 게임이 끝나는 시간을 계산하라.

// 결과 =====
// 1시간 30분 초과

// 내가 작성한 로직이 정상동작하는지 확실한 점검이 필요하다.
// 이거 head와 tail을 관리해서 하니까 tail 방향과 실제 다음 꼬리 방향의 불일치가 발생한다.

// 또한 사과 시작점을 착각하고있었다. 이런 바보같은..

#define N_MAX 100
#define DIRECTIONS 4

struct turn_info {
    int x;
    char c;
};

struct pos_info {
    int r = 0;
    int c = 0;
    int d = 0;
};

int n, k, l;
int map[N_MAX][N_MAX]; // 0으로 초기화 해줘야하나?
queue<turn_info> commands;

queue<pos_info> snake;

int dr[DIRECTIONS] = {0, 1, 0, -1};
int dc[DIRECTIONS] = {1, 0, -1, 0};

int play_time = 1; // 1초부터 시작한다 생각하자.
                    // 도대체 언제부터 시작인거지?
                    // "8초가 끝난 뒤에" 라는 표현 상으로 8.99가 지나고 9초가 되면 방향을 바꾼다는거 같다.

void print_map() {
    cout << "head: (" << snake.back().r << ", " << snake.back().c << "), d=" << snake.back().d << endl;
    cout << "tail: (" << snake.front().r << ", " << snake.front().c << "), d=" << snake.front().d << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << map[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void input() {
    if(LOG) cout << "input()" << endl;
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        map[--r][--c] = 2; // 사과 있는 장소는 2
    }
    cin >> l;
    for(int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c; // 입력 자료형 맞춰줘야한다.
        turn_info ti;
        ti.x = x; ti.c = c;
        commands.push(ti);
    }
}

void init() {
    if(LOG) cout << "init()" << endl;
    map[0][0] = 1; // 뱀이 있는 장소는 1로 초기화
    pos_info pi;
    snake.push(pi);
}

bool can_go() {
    if(LOG) cout << "can_go()" << endl;
    int nr = snake.back().r + dr[snake.back().d];
    int nc = snake.back().c + dc[snake.back().d];

    if(nr == -1 || nr == n || nc == -1 || nc == n) {
        return false;
    }
    else if(map[nr][nc] == 1) {
        return false;
    }

    return true;
}

bool is_apple() {
    if(LOG) cout << "is_apple()" << endl;
    int nr = snake.back().r + dr[snake.back().d];
    int nc = snake.back().c + dc[snake.back().d];

    if(map[nr][nc] != 2) {
        return false;
    }

    return true;
}

void eat_apple() {
    if(LOG) cout << "eat_apple()" << endl;
    int nr = snake.back().r + dr[snake.back().d];
    int nc = snake.back().c + dc[snake.back().d];

    // 뱀 연장
    pos_info pi; pi.r = nr; pi.c = nc; pi.d = snake.back().d;
    snake.push(pi);
    map[nr][nc] = 1;
}

void move() {
    // 방향 회전 후 tail을 지우지 못하는 문제가 있다.
    // 지금 방식은 tail에 방향도 담아서 지우고 head의 방향을 다시 tail에 담는 방식인데
    // 방향을 바꾸고 움직이면, tail 방향의 불일치가 발생한다.
    if(LOG) cout << "move()" << endl;
    int nr = snake.back().r + dr[snake.back().d];
    int nc = snake.back().c + dc[snake.back().d];

    pos_info pi; pi.r = nr; pi.c = nc; pi.d = snake.back().d;
    snake.push(pi);
    map[nr][nc] = 1;

    map[snake.front().r][snake.front().c] = 0;
    snake.pop();
}

void turn() {
    if(LOG) cout << "turn(x = " << commands.front().x << ", c = " << commands.front().c << ")" << endl;
    if(play_time != commands.front().x+1) return;

    if(commands.front().c == 'L') {
        snake.back().d--;
        if(snake.back().d < 0) snake.back().d = DIRECTIONS - 1;
    }
    else if(commands.front().c == 'D') {
        snake.back().d++;
        if(snake.back().d == DIRECTIONS) snake.back().d = 0;
    }

    commands.pop(); // 방향전환 했으면 날려줘야지ㅋㅋ
}

void solution() {
    while(true) {
        if(LOG) cout << "===========================" << endl;
        // if(LOG) cout << "play time: " << play_time << endl;
        // 머리 연장 후 자신 혹은 벽이면 종료
        if(can_go()) {
            // 이동 칸에 사과 여부 확인
            if(is_apple()) {
                eat_apple();
            }
            else {
                // 사과 없으면 꼬리 줄이기
                move();
            }
            if(LOG) print_map();

        }
        else {
            break;
        }

        play_time++;
        if(LOG) cout << play_time << " sec is over" << endl << endl;

        // 방향 전환
        // 큐로 관리해서 back()의 시간에 도달하면 방향 전환하고 pop()
        turn();

    } // 0초부터 시작하면 while 반복으로는 시작을 못한다.

    if(LOG) cout << endl << "You survive: ";
    cout << play_time;
}

void solve() {
    input();
    init();
    solution();
}

int main() {
    solve();
    return 0;
}