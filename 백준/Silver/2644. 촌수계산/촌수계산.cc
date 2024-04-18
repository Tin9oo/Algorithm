#include <iostream>
#include <vector>

using namespace std;

#define LOG false

struct relation_struct {
    int parent;
    vector<int> children;
};

int n, m;
pair<int, int> target;
// 앞이 부모, 뒤가 자식 // 각 사람의 부모는 최대 한 명
vector<relation_struct> jokbo;
vector<int> visited;

int answer = -1;

void input() {
    cin >> n;
    jokbo.resize(n+1);
    visited.resize(n+1);
    
    cin >> target.first >> target.second;

    cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        relation_struct rs;
        rs.parent = a;
        jokbo[b].parent = a;
        jokbo[a].children.push_back(b);
    }
}

void dfs(int num, int cnt) {
    if(LOG) cout << "dfs(num = " << num << ", cnt = " << cnt << ")" << endl;

    if(num == target.second) {
        answer = cnt;
        return;
    }

    // up
    if(visited[jokbo[num].parent] == 0 && jokbo[num].parent != 0) {
        visited[jokbo[num].parent] = 1;
        dfs(jokbo[num].parent, cnt + 1); // 부모가 없는 데 부모를 찾으면 이상한 부모를 참조한다.
    }

    // down
    for(auto c: jokbo[num].children) {
        if(visited[c] == 1) continue;
        visited[c] = 1;
        dfs(c, cnt + 1);
    }
}

void solution() {
    visited[target.first] = 1;
    dfs(target.first, 0);
}

int main() {
    input();
    solution();

    cout << answer;

    return 0;
}