#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // 컴퓨터 수 (100 이하 양의 정수)
int M; // 연결 쌍 수
vector<vector<int>> connections;

vector<int> visited;
int answer = 0;

void input() {
    cin >> N >> M;
    visited.resize(N+1);
    connections.resize(N+1, vector<int>(N+1)); // 컴퓨터 번호는 1 ~ N
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        connections[a][b] = 1;
        connections[b][a] = 1;
    }
}

void bfs() {
    queue<int> q;

    visited[1] = 1;
    q.push(1);

    while(!q.empty()) {
        int infected = q.front();
        q.pop();

        for(int i = 1; i <= N; i++) {
            if(visited[i] == 1) continue;
            if(connections[infected][i] != 1) continue;
            visited[i] = 1;
            answer++;
            q.push(i);
        }
    }
}

void solution() {
    bfs();
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