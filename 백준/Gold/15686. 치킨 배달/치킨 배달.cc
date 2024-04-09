#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define LOG false

// ===== 결과
// 1시간 초과
// 조건 맞춰주니까 또 되네ㅋㅋㅋ

// ===== 문제 개요
// r, c: 1부터 시작

// 치킨거리: 가장 가까운 치킨집까지의 거리

// 0: 빈칸
// 1: 집
// 2: 치킨집

// M개 선택했을 때 도시의 치킨거리가 최소가 되도록 하라.

// ===== 접근
// 집의 위치랑 치킨집 위치를 각각 저장한다.
// 각 집의 치킨거리를 구한다.
// 치킨거리를 길게 만드는 애를 찾고 지운다.
// 가장 짧은 치킨거리를 만드는 치킨집에 cnt를 올린다. cnt가 가장 적은 치킨집을 지운다.
// 그냥, 모든 치킨집 조합 만들어서 구하자.


#define N_MAX 50

int n, m;
int map[N_MAX][N_MAX];

vector<pair<int, int>> house;
vector<pair<int, int>> chick;

int answer = INT_MAX;

vector<int> selected;

void input() {
    if(LOG) cout << "input();" << endl;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];   // 인덱스를 n으로 해버려서 오류가 발생함
                                // 이후 초기화 되지 않은 인덱스에 접근 할 때 문제가 발생하게 됨
        }
    }
}

void print_chick() {
    for(auto c: chick) {
        cout << "(" << c.first << "," << c.second << ") ";
    }
    cout << endl;
}

void init() {
    if(LOG) cout << "init();" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 1) house.push_back({i, j});
            if(map[i][j] == 2) chick.push_back({i, j});
        }
    }
    for (int i = 0; i < chick.size()-m; i++) {
        selected.push_back(0);
    }
    for(int i = 0; i < m; i++) {
        selected.push_back(1);
    }
}

int get_dist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int get_city_dist() {
    int city_dist = 0;

    for(auto h: house) {
        int min_dist = INT_MAX;
        for(int i = 0; i < chick.size(); i++) {
            pair<int, int> c = chick[i];
            if(selected[i] == 1) {
                int dist = get_dist(h, c);
                if(min_dist > dist) {
                    min_dist = dist;
                }
            }
        }
        city_dist += min_dist;
    }

    return city_dist;
}

void perm() {
    if(LOG) cout << "perm();" << endl;
    do {
        if(LOG) print_chick();

        int city_dist = get_city_dist();
        if(answer > city_dist) {
            answer = city_dist;
            if(LOG) cout << "Answer is updated to " << answer << endl;
        }
    } while(next_permutation(selected.begin(), selected.end()));
}

void solution() {
    init();

    perm();

    cout << answer;
}

void solve() {
    input();
    solution();
}

int main() {
    solve();
    return 0;
}