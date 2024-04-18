#include <iostream>
#include <vector>

using namespace std;

// Abstract =====
/*
    NxM 종이 위에 테트로미노 하나를 놓는다.
    종이는 1x1 크기로 나뉘어 있으며 각 칸에 정수가 하나 써져 있다. 1000을 넘지 않는 자연수다.
    테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰인 수의 합을 구하는 프로그램을 작성하라.
    테트로미노는 회전이나 대칭이 가능하다.
*/

#define LOG false

#define TETRO_NUM 3
#define SHAPE_NUM 19

int N, M;
vector<vector<int>> paper;

vector<vector<int>> shape_dr = {
    {0, 0, 0}, {1, 2, 3},
    {0, 1, 1},
    {1, 2, 2}, {0, 0, 1}, {0, 1, 2}, {1, 1, 1}, {0, 1, 2}, {1, 1, 1}, {1, 2, 2}, {0, 0, 1},
    {1, 1, 2}, {0, 1, 1}, {1, 1, 2}, {0, 1, 1},
    {0, 0, 1}, {1, 1, 2}, {1, 1, 1}, {1, 1, 2}
};

vector<vector<int>> shape_dc = {
    {1, 2, 3}, {0, 0, 0},
    {1, 0, 1},
    {0, 0, 1}, {1, 2, 0}, {1, 1, 1}, {-2, -1, 0}, {1, 0, 0}, {0, 1, 2}, {0, 0, -1}, {1, 2, 2},
    {-1, 0, -1}, {1, 1, 2}, {0, 1, 1}, {1, -1, 0},
    {1, 2, 1}, {-1, 0, 0}, {-1, 0, 1}, {0, 1, 0}
};

int answer = 0;

void input() {
    cin >> N >> M;
    paper.resize(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }
}

int put_tet(int r, int c) {
    int sum, max_sum = 0;

    int nr, nc;

    for(int i = 0; i < SHAPE_NUM; i++) {
        sum = paper[r][c];
        for(int j = 0; j < TETRO_NUM; j++) {
            nr = r + shape_dr[i][j];
            nc = c + shape_dc[i][j];

            if(nr < 0 || N <= nr || nc < 0 || M <= nc) break;

            sum += paper[nr][nc];

            if(j == TETRO_NUM - 1 && max_sum < sum) {
                max_sum = sum;
                // if(LOG) cout << i << "-th shape can update max_sum to " << max_sum << endl;
            }
        }
    }

    return max_sum;
}

void solution() {
    int max_sum = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            max_sum = put_tet(i, j); 
            if(answer < max_sum) {
                answer = max_sum;
                if(LOG) cout << "(r = " << i << ", c = " << j << ") : is update answer to " << answer << endl;
            }       
        }
    }
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