#include <iostream>
#include <queue>

using namespace std;

#define LOG false

struct bfs_info {
    int floor;
    int cnt;
};

int F, S, G, U, D;

vector<int> visited;

int answer = -1;

void bfs() {
    queue<bfs_info> q;

    bfs_info bi;
    bi.floor = S; bi.cnt = 0;

    visited[bi.floor] = 1;
    q.push(bi); 

    while(!q.empty()) {
        bi = q.front();
        q.pop();

        if(LOG) cout << "bi.floor = " << bi.floor << ", bi.cnt = " << bi.cnt << endl;

        if(bi.floor == G) {
            answer = bi.cnt;
            return;
        }

        for(int i = 0; i < 2; i++) {
            bfs_info nbi;
            if(i == 0) nbi.floor = bi.floor + U;
            else if(i == 1) nbi.floor = bi.floor - D;

            if(nbi.floor <= 0 || F < nbi.floor) continue;
            if(visited[nbi.floor] == 1) continue; // 범위가 정상인지 판단 하고 봐야한다.

            nbi.cnt = bi.cnt + 1;

            visited[nbi.floor] = 1;
            q.push(nbi);
        }
    }

    cout << "use the stairs";
}

int main() {
    cin >> F >> S >> G >> U >> D;
    visited.resize(F+1);

    bfs();

    if(answer != -1) cout << answer; // 시작과 끝이 같으면 0이 나올 수 있다.

    return 0;
}