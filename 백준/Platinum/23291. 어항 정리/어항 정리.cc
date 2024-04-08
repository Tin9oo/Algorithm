#include <iostream>
#include <deque>
#include <climits>
#include <vector>
using namespace std;

// https://yabmoons.tistory.com/734

#define MAX 110 // 왜 110이지?

int n, k;
deque<int> bowl[MAX];

int dx[] = {0, -1};
int dy[] = {1, 0};

void input() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        bowl[0].push_back(a);
    }
}

bool check() {
    int min_fish = INT_MAX;
    int max_fish = INT_MIN;

    for(int i = 0; i < bowl[0].size(); i++) {
        min_fish = min(min_fish, bowl[0][i]);
        max_fish = max(max_fish, bowl[0][i]);
    }
    
    return max_fish - min_fish <= k ? true : false;
}

void add_fish() {
    int min = INT_MAX;
    vector<int> idx;
    for(int i = 0; i < bowl[0].size(); i++) {
        if(bowl[0][i] < min) {
            min = bowl[0][i];
            idx.clear();
            idx.push_back(i);
        }
        else if(bowl[0][i] == min) {
            idx.push_back(i);
        }
    }
    for(auto i: idx) {
        bowl[0][i]++;
    }
}

bool can_build(int w, int h) {
    if(bowl[0].size() - w < h) {
        return false;
    }
    return true;
}

void print() {
    for(int i = 0; i < 5; i++) {
        if(bowl[i].size() == 0) continue;
        for(int j = 0; j < bowl[i].size(); j++) {
            cout << bowl[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int build_bowl() {
    int width = 1;
    int height = 1;
    bool flag = false;

    while(1) {
        if(can_build(width, height) == false) {
            break;
        }

        int tmpWidth = width;

        for(int i = 0; i < width; i++, tmpWidth--) {
            int idx = 0;
            for(int j = 0; j < height; j++) {
                bowl[tmpWidth].push_back(bowl[j][i]);
            }
        }

        for(int i = 0; i < height; i++) {
            for(int j = 0;j < width; j++) {
                bowl[i].pop_front();
            }
        }

        if(flag == false) {
            height++;
            flag = true;
        }
        else {
            width++;
            flag = false;
        }
    }

    return height;
}

void adjust_fish(int height) {
    deque<int> tmpbowl[MAX];
    for(int i = 0; i < height; i++) {
        tmpbowl[i] = bowl[i];
    }

    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j < bowl[i].size(); j++) {
            int x = i;
            int y = j;
            int num = bowl[x][y];
            for(int k = 0; k < 2; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && ny < bowl[i].size()) {
                    int num2 = bowl[nx][ny];
                    int diff = abs(num - num2) / 5;
                    if(diff > 0) {
                        if(num > num2) {
                            tmpbowl[x][y] -= diff;
                            tmpbowl[nx][ny] += diff;
                        }
                        else {
                            tmpbowl[x][y] += diff;
                            tmpbowl[nx][ny] -= diff;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < height; i++) {
        bowl[i] = tmpbowl[i];
    }
}

void spread_bowl(int height) {
    int width = bowl[height-1].size();
    int size = bowl[0].size();

    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            bowl[0].push_back(bowl[j][i]);
        }
    }

    for(int i = 1; i < height; i++) {
        bowl[i].clear();
    }

    for(int i = width; i < size; i++) {
        bowl[0].push_back(bowl[0][i]);
    }

    for(int i = 0; i < size; i++) {
        bowl[0].pop_front();
    }
}

void build_bowl2() {
    int n = bowl[0].size();
    for(int i = 0; i < n / 2; i++) {
        bowl[1].push_front(bowl[0][i]);
    }
    for(int i = 0; i < n / 2; i++) {
        bowl[0].pop_front();
    }
    for(int i = 0; i < n / 4; i++) {
        bowl[2].push_front(bowl[1][i]);
        bowl[3].push_front(bowl[0][i]);
    }
    for(int i = 0; i < n / 4; i++) {
        bowl[0].pop_front();
        bowl[1].pop_front();
    }
}

void solution() {
    int answer = 0;
    while(1) {
        if(check() == true) {
            cout << answer << endl;
            break;
        }

        add_fish();
        int height = build_bowl();
        // print();
        adjust_fish(height);
        spread_bowl(height);
        // print();
        build_bowl2();
        // print();
        adjust_fish(4);
        spread_bowl(4);
        // print();
        answer++;
    }
}

void solve() {
    input();
    solution();
}

int main() {
    solve();

    return 0;
}