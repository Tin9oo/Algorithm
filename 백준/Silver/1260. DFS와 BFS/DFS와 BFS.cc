#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define LOG false

int N; // 정점의 개수
int M; // 간선의 개수
int V; // 시자 정점
vector<vector<int>> graph;

vector<int> dfs_vis;
vector<int> bfs_vis;

vector<int> dfs_visited;

void input() {
    cin >> N >> M >> V;

    graph.resize(N+1, vector<int>(N+1));
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
}

void dfs(int v_before) {
    if(LOG) cout << "dfs(" << v_before << ")" << endl;

    for(int i = 1; i <= N; i++) {
        if(dfs_visited[i] == 1) continue;
        if(graph[v_before][i] == 0) continue;

        dfs_visited[i] = 1;
        dfs_vis.push_back(i);
        dfs(i);
    }

    return;
}

void bfs() {
    vector<int> visited(N+1);
    visited[V] = 1;

    queue<int> q;
    visited[V] = 1;
    bfs_vis.push_back(V);
    q.push(V);

    while(!q.empty()) {
        int v_before = q.front();
        q.pop();

        for(int i = 1; i <= N; i++) {
            if(visited[i] == 1) continue;
            if(graph[v_before][i] == 0) continue;

            visited[i] = 1;
            bfs_vis.push_back(i);
            q.push(i);
        }
    }
}

void solution() {
    dfs_visited.resize(N+1);
    dfs_visited[V] = 1;
    dfs_vis.push_back(V);
    dfs(V);

    bfs();
}

void output() {
    for(auto dv: dfs_vis) cout << dv << " ";
    cout << endl;
    for(auto bv: bfs_vis) cout << bv << " ";
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