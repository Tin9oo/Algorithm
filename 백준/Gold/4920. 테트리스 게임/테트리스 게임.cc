#include <iostream>
#include <deque>
#include <climits>

using namespace std;

// 결과 =====
// 실패 (1시간 30분)
// 어케푸냐;;

// 개요 =====
// 주어진 블록을 판 위에 올려서 블록에 겹치는 수의 최댓값을 구한다.
// 블록은 90도로 회전할 수 있다.

// 접근 =====
// 그냥 풀면 될거같긴 한데, 쉬운거를 봐서는 최적화를 좀 해야하나?

// 도형 조각이 정해져 있다.
// 도형을 좌측 상단부터 Z 방향으로 내려보낸다. <= Deque 쓰면 내리는거 할만할거같은데

// 정해진 모양을 만들어볼까?

// 그냥 도형의 시작점을 잡고 i, j로 모든 칸을 이동하며 도형을 만들 수 있으면 합을 구하는 방식이 좋아보인다.

// 시작지점으로부터 이동하는 패턴을 먼저 만든다.
// 

#define LOG false

#define N_MAX 100

int t = 0;
int n; // 4 <= N <= 100
int map[N_MAX][N_MAX];  // 각 숫자는 절댓값이 1,000,000을 넘지 않는 정수다.
                        // 매번 초기화 해줘야한다.
                        // 어차피 n 크기만큼만 사용할거니까 초기화 필요 없을지도?
int trash;

int pattern_r[][3] = { // 중심 좌표로부터 얼마나 떨어져 있는지를 담는다.
    {0, 0, 0}, {1, 2, 3}, // 패턴 1
    {0, 1, 1}, {1, 1, 2}, // 패턴 2
    {0, 0, 1}, {1, 2, 2}, {1, 1, 1}, {0, 1, 2}, // 패턴 3
    {0, 0, 1}, {-1, 0, 1}, {1, 1, 1}, {-1, 0, 1}, // 패턴 4
    {0, 1, 1} // 패턴 5
};

int pattern_c[][3] = { // 중심 좌표로부터 얼마나 떨어져 있는지를 담는다.
    {1, 2, 3}, {0, 0, 0}, // 패턴 1
    {1, 1, 2}, {0, -1, -1}, // 패턴 2
    {1, 2, 2}, {0, 0, -1}, {0, 1, 2}, {-1, -1, -1}, // 패턴 3
    {-1, 1, 0}, {0, -1, 0}, {-1, 0, 1}, {0, 1, 0}, // 패턴 4
    {1, 0, 1} // 패턴 5
};

int answer;

void print_map() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << map[i][j] << "\t";
        }
        cout << endl;
    }
}

void init() {
    t++;
    answer = INT_MIN;
}

void input() {
    // 입력의 마지막 줄에는 0이 하나 주어진다.
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
}

void place(int r, int c) {
    int sum;
    bool flag;

    for(int i = 0; i < 13; i++) { // 패턴 개수
        if(LOG) cout << "(" << r << ", " << c << ")\t";

        sum = map[r][c];
        flag = false;

        for(int j = 0; j < 3; j++) {
            int nr = r + pattern_r[i][j];
            int nc = c + pattern_c[i][j];

            if(LOG) cout << "(" << nr << ", " << nc << ")\t";

            if(0 <= nr&&nr < n && 0 <= nc&&nc < n) { // 기준 오타내지 마라.
                sum += map[nr][nc];
            }
            else {
                if(LOG) cout << "can not place!!" << endl;
                flag = true;
                break;
            }
        }
        if(flag) continue;

        if(answer < sum) {
            answer = sum;
            if(LOG) cout << "answer is updated!! : " << answer << endl;
        }
    }
}

void solution() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            place(i, j);
        }
    }
}

void output() {
    cout << t << ". " << answer << endl;
}

void solve() {
    while(true) {
        init();
        input();
        if(n==0) break;
        solution();
        output();
    }
}

int main() {
    solve();
    return 0;
}