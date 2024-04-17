#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 전역변수 쓰다가 같은 이름으로 지역변수 만들어서 문제 생김 아..

#define LOG false

struct heater_info {
    int r, c, d;
};

struct wind_info {
    int r, c, amount;
};

struct inspect_info {
    int r, c;
};

struct wall_info {
    int x, y, t;
};

int R, C, K;
vector<vector<int>> map;
vector<heater_info> heater;
vector<inspect_info> target;

int W;
vector<wall_info> wall_vec;

int num_choco = 0;

vector<int> dr = {-1, 0, 1, 0}; // 상, 우, 하, 좌
vector<int> dc = {0, 1, 0, -1};

vector<vector<int>> wdr = {
    {-1, -1, -1}, {-1, 0, 1}, {1, 1, 1}, {1, 0, -1}
};
vector<vector<int>> wdc = {
    {-1, 0, 1}, {1, 1, 1}, {1, 0, -1}, {-1, -1, -1}
};

void print_map() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j< C; j++) {
            cout << map[i][j];
            for(auto w: wall_vec) {
                if(w.x==i && w.y==j) {
                    cout << " (" << w.t << ")";
                }
            }
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void input() {
    cin >> R >> C >> K;

    // 방 구조
    int tmp;
    map.resize(R, vector<int>(C, 0));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> tmp;
            if(1 <= tmp && tmp <= 4) {
                heater_info h;
                h.r = i; h.c = j; h.d = tmp;
                heater.push_back(h);
            }
            else if(tmp == 5) {
                inspect_info ii;
                ii.r = i; ii.c = j;
                target.push_back(ii);
            }
        }
    }

    // 벽 정보 (좌표를 0부터 시작하게 해야한다.)
    cin >> W;
    for(int i = 0; i < W; i++) {
        wall_info tmp;
        cin >> tmp.x >> tmp.y >> tmp.t;
        tmp.x--; tmp.y--;
        wall_vec.push_back(tmp);
    }
}

int dir_to_my_dir(int d) {
    if(d == 1) {
        return 1;
    }
    else if(d == 2) {
        return 3;
    }
    else if(d == 3) {
        return 0;
    }
    else if(d == 4) {
        return 2;
    }

    return -1;
}

bool is_wall(int r, int c, int d) {
    int nr = r + dr[d];
    int nc = c + dc[d];
    
    for(auto w: wall_vec) {
        if(d == 0) {
            if(r == w.x && c == w.y) {
                if(w.t == 0) return true;
            }
        }
        else if(d == 1) {
            if(r == w.x && c == w.y) {
                if(w.t == 1) return true;
            }
        }
        else if(d == 2) {
            if(nr == w.x && nc == w.y) {
                if(w.t == 0) return true;
            }
        }
        else if(d == 3) {
            if(nr == w.x && nc == w.y) {
                if(w.t == 1) return true;
            }
        }
    }
    return false;
}

bool can_blow(int r, int c, int d, int idx) {
    int nr;
    int nc;
    int nd;

    bool flag = false;

    if(idx == 0) {
        nd = (d-1 < 0) ? (3) : (d-1);
        nr = r + dr[nd];
        nc = c + dc[nd];
        if(!is_wall(r, c, nd)) {
            if(!is_wall(nr, nc, d)) {
                flag = true;
            }
        }
    }
    else if(idx == 1) {
        flag = !is_wall(r, c, d);
    }
    else if(idx == 2) {
        nd = (d+1 == 4) ? (0) : (d+1);
        nr = r + dr[nd];
        nc = c + dc[nd];
        if(!is_wall(r, c, nd)) {
            if(!is_wall(nr, nc, d)) {
                flag = true;
            }
        }
    }

    return flag;
}

void blow(int r, int c, int d) {
    if(LOG) cout << "blow(r=" << r << ",c=" << c << ",d=" << d << ")" << endl;
    vector<vector<int>> visited(R, vector<int>(C));
    d = dir_to_my_dir(d);

    int nr = r + dr[d];
    int nc = c + dc[d];

    wind_info wi;
    wi.r = nr; wi.c = nc; wi.amount = 5;

    queue<wind_info> q;
    q.push(wi);

    while(!q.empty()) {
        int qr = q.front().r;
        int qc = q.front().c;
        int qamount = q.front().amount;
        // if(LOG) cout << "qr=" << qr << ",qc=" << qc << endl;
        q.pop();

        map[qr][qc] += qamount;
        // if(LOG) print_map();
        if(qamount == 1) continue;

        for(int i = 0; i < 3; i++) {
            int qnr = qr + wdr[d][i];
            int qnc = qc + wdc[d][i];
                // if(LOG) cout << "qnr=" << qnr << ",qnc=" << qnc << endl;

            if(0 <= qnr&&qnr < R && 0 <= qnc&&qnc < C) {
                if(visited[qnr][qnc] == 0 && can_blow(qr, qc, d, i)) {
                    visited[qnr][qnc] = 1;
                    wind_info qwi;
                    qwi.r = qnr; qwi.c = qnc; qwi.amount = qamount - 1;
                    q.push(qwi);
                }
            }
        }
    }
}

void select_heater() {
    if(LOG) cout << "select_heater()" << endl;
    for(auto h: heater) {
        blow(h.r, h.c, h.d);
        if(LOG) print_map();
    }
}

void adjust_temperature() {
    if(LOG) cout << "adjust_temperature()" << endl;
    // 온도가 0이면 감소하지 않는다.
    // 벽으로 막혀있으면 온도 변화가 없다.
    vector<vector<int>> tmp_map = map;
    int diff;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) { // C-1까지 반복하면 C열의 원소는 아래 방향 탐색이 없어서 덜 탐색하게된다.
            if(LOG) cout << "j=" << i << ", j=" << j << endl;
            if(j+1 < C && !is_wall(i, j, 1)) {
                if(LOG) cout << "right:" << endl;
                diff = (map[i][j] - map[i][j+1]) / 4;
                if(LOG) cout << "diff=" << diff << endl;
                tmp_map[i][j] -= diff;
                tmp_map[i][j+1] += diff;
            }
            
            if(i+1 < R && !is_wall(i, j, 2)) {
                if(LOG) cout << "down:" << endl;
                diff = (map[i][j] - map[i+1][j]) / 4;
                if(LOG) cout << "diff=" << diff << endl;
                tmp_map[i][j] -= diff; // diff가 음수일 때 += 연산을 하면 의도와 다르게 동작한다. 커지지 않고 작아진다.
                tmp_map[i+1][j] += diff;
            }


            if(tmp_map[i][j] < 0) tmp_map[i][j] = 0;
            if(j+1 < C && tmp_map[i][j+1] < 0) tmp_map[i][j+1] = 0;
            if(i+1 < R && tmp_map[i+1][j] < 0) tmp_map[i+1][j] = 0;

            if(LOG) cout << endl;
        }
    }

    map = tmp_map;

    if(LOG) print_map();
}

void decrease_outline() {
    if(LOG) cout << "decrease_outline()" << endl;
    for(int i = 0; i < C; i++) {
        if(map[0][i] > 0) map[0][i]--;
        if(map[R-1][i] > 0) map[R-1][i]--;
    }
    for(int i = 1; i < R-1; i++) {
        if(map[i][0] > 0) map[i][0]--;
        if(map[i][C-1] > 0) map[i][C-1]--;
    }
    if(LOG) print_map();
}

void eat_choco() {
    num_choco++;
}

bool check() {
    for(auto t: target) {
        if(map[t.r][t.c] < K) {
            return false;
        }
    }
    return true;
}

void solution() {
    while(true) {
        select_heater();
        adjust_temperature();
        decrease_outline();
        eat_choco();
        if(num_choco > 100) break;
        if(check()) break;
    }
}

void output() {
    if(LOG) print_map();
    cout << num_choco;
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