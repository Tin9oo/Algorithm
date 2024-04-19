#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define LOG false

#define N_MAX 100000
#define DIRECTIONS 3

int N, K;

vector<int> cnt_map;
vector<int> visited;

int dx[DIRECTIONS] = {2, 1, -1};

int answer;

void input() {
    cin >> N >> K;
    cnt_map.resize(N_MAX*2);
    visited.resize(N_MAX*2);
}

void bfs() {
    queue<int> q;

    visited[N] = 1;

    q.push(N);

    while(!q.empty()) {
        int pos = q.front();
        q.pop();

        if(LOG) cout << "current pos : " << pos << ",\tcnt_map[pos] : " << cnt_map[pos] << endl;

        // for(int i = 0; i < DIRECTIONS; i++) {
        //     int np;
        //     if(i == 0) np = pos * dx[i];
        //     else np = pos + dx[i];

        //     if(visited[np] == 1) {continue;}
        // }

        if(pos != 0) {
            int np = pos * 2;

            if(0 < np && np < 2 * N_MAX && visited[np] == 0) {
                if(np == K) {
                    answer = cnt_map[pos] + 1;
                    return;
                }

                cnt_map[np] = cnt_map[pos] + 1;
                visited[np] = 1;
                q.push(np);
            }
        }

        if(pos + 1 <= 2*N_MAX && visited[pos + 1] == 0) {
            if(pos + 1 == K) {
                answer = cnt_map[pos] + 1;
                return;
            }
            cnt_map[pos + 1] = cnt_map[pos] + 1;
            visited[pos + 1] = 1;
            q.push(pos + 1);
        }

        if(pos - 1 >= 0 && visited[pos - 1] == 0) {
            if(pos - 1 == K) {
                answer = cnt_map[pos] + 1;
                return;
            }
            cnt_map[pos - 1] = cnt_map[pos] + 1;
            visited[pos - 1] = 1;
            q.push(pos - 1);
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