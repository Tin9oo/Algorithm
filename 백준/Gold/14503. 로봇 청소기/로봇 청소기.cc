#include <iostream>

using namespace std;

#define LOG false

#define MAX 50
#define DIRECTIONS 4

int n, m;
int r, c, d;
int map[MAX][MAX] = {};
// 0: 청소 안함
// 1: 벽
// 2: 청소 함

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int answer = 0;

void input() {
    if(LOG) cout << "input()" << endl;
    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
}

bool can_clean() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0) return true;
        }
    }
    return false;
}

void clean() {
    if(LOG) cout << "clean()" << endl;
    map[r][c] = 2;
    answer++;
}

bool check_around() {
    for(int i = 0; i < DIRECTIONS; i++) {
        int ni = r+di[i];
        int nj = c+dj[i];

        if(0<=ni&&ni<n && 0<=nj&&nj<m) {
            if(map[ni][nj] == 0) {
                return true;
            }
        }
    }

    return false;
}

void turn() {
    d--;
    if(d < 0) {
        d = DIRECTIONS - 1;
    }
}

bool check_back() {
    int back_d = ( d + 2 ) % DIRECTIONS;

    int ni = r+di[back_d];
    int nj = c+dj[back_d];

    if(0<=ni&&ni<n && 0<=nj&&nj<m) {
        if(map[ni][nj] == 1) {
            return false;
        }
    }

    return true;
}

void back() {
    r-=di[d];
    c-=dj[d];
}

bool can_front() {
    int ni = r+di[d];
    int nj = c+dj[d];

    if(0<=ni&&ni<n && 0<=nj&&nj<m) {
        if(map[ni][nj] == 0) {
            return true;
        }
    }

    return false;
}

void move_front() {
    r+=di[d];
    c+=dj[d];
}

void solution() {
    while(1) {
        if(can_clean() == false) {
            break;
        }

        // 1
        if(map[r][c]==0) {
            clean();
        }

        // 2
        if(check_around() == false) {
            if(check_back() == true) {
                back();
                continue;
            }
            else {
                break;
            }
        }
        else { // 3
            turn();
            if(can_front() == true) {
                move_front();
            }
        }
    }
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