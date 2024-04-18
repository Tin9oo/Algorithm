#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define LOG false

#define DIRECTIONS 4

struct position {
    int r, c;
};

int N, M;
vector<vector<int>> map;

int dr[DIRECTIONS] = {-1, 0, 1, 0};
int dc[DIRECTIONS] = {0, 1, 0, -1};

int answer;

void print_2dvec(vector<vector<int>> vec) {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void input () {
    cin >> N >> M;

    map.resize(N+1, vector<int>(M+1));

    for(int i = 1; i <= N; i++) { // 하 이것도 한줄 입력이네..
        string s;
        cin >> s;

        for(int j = 1; j <= M; j++) {
            // if(LOG) cout << "(" << i << ", " << j << ")" << endl;

            map[i][j] = s[j-1] - '0';
        }
    }
    if(LOG) print_2dvec(map);
    // if(LOG) cout << "end input()" << endl;
}

void bfs() {
    vector<vector<int>> visited(N+1, vector<int>(M+1));
    vector<vector<int>> cnt_map(N+1, vector<int>(M+1));

    position p;
    p.r = 1; p.c = 1;

    visited[p.r][p.c] = 1;

    queue<position> q;
    cnt_map[p.r][p.c]++;
    q.push(p);

    while(!q.empty()) {
        position np = q.front();
        q.pop();

        if(LOG) cout << "r = " << np.r << ", c = " << np.c << endl;

        if(np.r == N && np.c == M) {
            answer = cnt_map[np.r][np.c];
            return;
        }
        
        for(int i = 0; i < DIRECTIONS; i++) {
            int nr = np.r + dr[i];
            int nc = np.c + dc[i];

            if(nr < 1 || N < nr || nc < 1 || M < nc) continue;
            if(map[nr][nc] == 0) continue;
            if(visited[nr][nc] == 1) continue;

            position tmp_p;
            tmp_p.r = nr; tmp_p.c = nc;

            cnt_map[nr][nc] = cnt_map[np.r][np.c] + 1;
            if(LOG) print_2dvec(cnt_map);

            visited[nr][nc] = 1;
            q.push(tmp_p);
        }
    }
}

void solution() {
    bfs();
}

int main() {
    input();
    solution();

    cout << answer;

    return 0;
}