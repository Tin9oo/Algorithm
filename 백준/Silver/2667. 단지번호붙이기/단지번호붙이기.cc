#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define LOG false

#define DIRECTIONS 4

int N;
vector<vector<int>> map;
vector<vector<int>> visited;

int dr[DIRECTIONS] = {-1, 0, 1, 0};
int dc[DIRECTIONS] = {0, 1, 0, -1};

int dan = 0;
vector<int> dan_cells;

void print_map() {
    for(auto v: map) {
        for(auto vv: v) {
            cout << vv << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void input() {
    cin >> N;
    map.resize(N, vector<int>(N));
    visited.resize(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        for(int j = 0; j < N; j++) {
            map[i][j] = s[j] - '0';
        }
    }
}

void bfs(int r, int c, int dan) {
    int cnt = 1;

    queue<pair<int, int>> q;
    q.push({r, c});

    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();

        map[p.first][p.second] = dan;
        if(LOG) cout << p.first << ", " << p.second << ", " << cnt << endl;

        for(int i = 0; i < DIRECTIONS; i++) {
            int nr = p.first + dr[i];
            int nc = p.second + dc[i];

            if(nr < 0 || N <= nr || nc < 0 || N <= nc) continue;
            if(visited[nr][nc] == 1) continue;
            if(map[nr][nc] == 0) continue;

            visited[nr][nc] = 1; // 큐에 삽입할 때 미리 예약한다는 개념이다.
                                            // 미리 예약하지 않으면, 내가 해당 장소에 값을 삽입할 게획이지만 실제로 넣기 전에 다른애도 넣고자 할 수 있기  때문이다.
            cnt++;
            q.push({nr, nc});
        }
    }

    dan_cells.push_back(cnt);
}

void solution() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j] == 1) continue;
            if(map[i][j] == 0) continue;

            visited[i][j] = 1;
            bfs(i, j, ++dan);
            if(LOG) print_map();
        }
    }
}

int main() {
    input();
    solution();

    sort(dan_cells.begin(), dan_cells.end());

    cout << dan << endl;
    for(auto dc: dan_cells) {
        cout << dc << endl;
    }

    return 0;
}