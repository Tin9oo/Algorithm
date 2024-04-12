#include <iostream>
#include <deque>

using namespace std;

// 개요 =====
// 격자의 끝을 넘어서면 반대쪽으로 연결된다.
// 최초 시전 시 (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름이 생긴다.
// 구름 M번 이동. 각 이동은 이동방향(d)와 거리(s)로 이루어져 있다.
// 8개의 방향을 정수로 표현한다. 서쪽부터 시계방향으로 1부터 커진다.

// 이동 순서는 다음과 같다.
// 1. 모둔 구름이 이동 명령을 따라 이동한다.
// 2. 각 구름에서 비가 내린다. 해당 칸의 바구니에 저장된 물의 양이 1 증가
// 3. 구름이 모두 사라진다.
// 4. 2번에서 물이 증가한 칸에 물복사 버그를 사용. -> 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수 만큼 현재 칸의 바구니 물 양이 증가
//   - 이동과 다르게 경계를 넘어가면 거리 1이 아니다.
// 5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생긴 후 물의 양이 2 줄어든다. 이때, 구름이 생긴 칸은 3에서 구름이사라진 칸이 아니어야 한다.

// M번의 이동이 끝난 후 바구니에 들은 물의 양을 합쳐보자.

#define LOG false

#define N_MAX 50
#define M_MAX 100
#define DIRECTION_NUM 8

struct move_info {
    int d;
    int s;
};

int n, m;
int a[N_MAX][N_MAX];
move_info b[M_MAX];

deque<deque<int>> cloud_map;

int dr[1 + DIRECTION_NUM] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dc[1 + DIRECTION_NUM] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

void print_map() {
    cout << "[a]\t\t\t\t\t\t[cloud_map]" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        for(int j = 0; j < n; j++) {
            cout << "\t" << cloud_map[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void input() {
    if(LOG) cout << "input()" << endl;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i].d >> b[i].s;
    }
}

void init() {
    cloud_map = deque<deque<int>>(n, deque<int>(n));
}

void bibaragi() {
    if(LOG) cout << "bibaragi()" << endl;
    cloud_map[n-1][0] = 1;
    cloud_map[n-1][1] = 1;
    cloud_map[n-2][0] = 1;
    cloud_map[n-2][1] = 1;

    if(LOG) print_map();
}

void move(move_info mi) {
    if(LOG) cout << "move(mi.d = " << mi.d << ", mi.s = " << mi.s << ")" << endl;

    for(int i = 0; i < mi.s; i++) {
        // 상하 이동
        if(dr[mi.d] == -1) { // 상
            cloud_map.push_back(cloud_map.front());
            cloud_map.pop_front();
        }
        else if(dr[mi.d] == 1) { // 하
            cloud_map.push_front(cloud_map.back());
            cloud_map.pop_back();
        }

        // 좌우 이동
        for(int j = 0; j < n; j++) {
            if(dc[mi.d] == -1) { // 좌
                cloud_map[j].push_back(cloud_map[j].front());
                cloud_map[j].pop_front();
            }
            else if(dc[mi.d] == 1) { // 우
                cloud_map[j].push_front(cloud_map[j].back());
                cloud_map[j].pop_back();
            }
        }
    }

    if(LOG) print_map();
}

void rain() {
    if(LOG) cout << "rain()" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cloud_map[i][j] != 1) continue;
            a[i][j]++;
            cloud_map[i][j] = -1; // 비가 방금 내렸다는 사실을 -1로 표시하면 이후 구름 생성할 때 ++로 생성하면 비가 내렸던 장소는 0이되고 안내렸던 곳은 1이 된다. 나 천재?
        }
    }
    if(LOG) print_map();
}

int adj_diag_water(int r, int c) {
    int cnt = 0;

    for(int i = 2; i < 1+DIRECTION_NUM; i+=2) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(0 <= nr&&nr < n && 0 <= nc&&nc < n) {
            if(a[nr][nc] > 0) cnt++;
        }
    }

    return cnt;
}

void dup_water() {
    if(LOG) cout << "dup_water()" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cloud_map[i][j] != -1) continue;
            a[i][j] += adj_diag_water(i, j);    // 순차적으로 물이 복사되기 때문에 나중의 물 복사 칸이 이전 변화에 영향을 받나?
                                                // 직전에 비가 내려 1이 되기 때문엥 영향을 받지 않는다.
                                                // 0에서 물복사로 값이 생겼다면 이후 물 복사 과정에서 영향이 생기겠지만 지금은 그렇지 않다.
        }
    }
    if(LOG) print_map();
}

void new_cloud() {
    if(LOG) cout << "new_cloud()" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] < 2) {
                cloud_map[i][j] = 0; // 2 미만이므로 구름이 생성되지 않는다. 구름이 있던 자리라는 표식을 제거한다.
                continue;
            }
            if(cloud_map[i][j] != -1) a[i][j] -= 2; // 구름이 있던 자리는 새로 생성되지 않으므로 물이 줄어들지 않는다.
            cloud_map[i][j]++;
        }
    }
    if(LOG) print_map();
}

int get_total_water() {
    int answer = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            answer += a[i][j];
        }
    }

    return answer;
}

void solution() {
    // 구름 생성
    bibaragi();
    
    for(int i = 0; i < m; i++) {
        // 이동
        // - 칸 넘어가는거는 % 써서 간단하게 해결 가능할듯
        // - deque로 이동하면 쉽게 만들 수 있을거같은데?
        move(b[i]);
        
        // 비 내리고 삭제 (바구니 채워짐)
        rain();
        
        // 물복사 버그 (물이 증가한 칸에만 적용)
        dup_water();
        
        // 직전에 구름 있던 자리 제외하고 2 이상인 자리에 구름 생성하고 2 감소
        // - 직전 구름 자리를 -1로 초기화 했으니 2이상인 자리에 ++하면 정상적으로 동작한다.
        new_cloud();
    }

    if(LOG) cout << "Total water = ";
    cout << get_total_water();
}

void solve() {
    input();
    init(); // 초기화 해줘야 cloud_map에 접근할 수 있다.
    solution();
}

int main() {
    solve();

    return 0;
}