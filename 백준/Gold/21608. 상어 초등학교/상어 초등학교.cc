#include <iostream>
#include <vector>

using namespace std;

#define LOG false

// 1시간 40분 실패
// 사전 설계가 좀 부족했다.
// 데이터구조가 머리속에 그려지지 않으면 아직 설계가 덜된거다. 적어도 나에게는..
// 데이터 만들 때 복잡하게 일부만 만들생각하지 말고 전부 만들어서 일부만 사용하는 방식이 좋을 수도 있다.

#define N_MAX 20
#define LIKE_NUM 4
#define DIRECTION_NUM 4

struct student {
    int num;
    int like_arr[LIKE_NUM];
};

struct seat_info {
    int num = -1; // -1이면 blank
    int num_like = 0;
    int num_blank = 0;
    bool target = false;
};

int n;
student s_arr[N_MAX*N_MAX];
seat_info classroom[N_MAX][N_MAX];

int dr[DIRECTION_NUM] = {-1, 0, 1, 0};
int dc[DIRECTION_NUM] = {0, 1, 0, -1};

void print_input() {
    cout << "print_input()" << endl;
    cout << "n: " << n << endl;
    for(int i = 0; i < n*n; i++) {
        cout << "num: " << s_arr[i].num << endl;
        cout << "like: {" << endl;
        for(auto l: s_arr[i].like_arr) {
            cout << "\t" << l << ", ";
        }
        cout << "}" << endl;
    }
}

void print_classroom() {
    cout << "print_classroom()" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << classroom[i][j].num << " (" << classroom[i][j].num_like << ", " << classroom[i][j].num_blank << ", " << classroom[i][j].target << ")\t";
        }
        cout << endl;
    }
    cout << endl;
}

void input() {
    if(LOG) cout << "input()" << endl;
    cin >> n;
    for(int i = 0; i < n*n; i++) {
        cin >> s_arr[i].num;
        for(int j = 0; j < LIKE_NUM; j++) { // 최신 방식으로 반복문을 사용하면 값 입력이 안된다.
            cin >> s_arr[i].like_arr[j];
        }
    }
    if(LOG) print_input();
    if(LOG) print_classroom();
}

void set_first_seat() {
    if(LOG) cout << "first_seat()" << endl;
    classroom[1][1].num = s_arr[0].num;
    if(LOG) print_classroom();
}

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(classroom[i][j].num == -1) {
                classroom[i][j].num_blank = 0;
                classroom[i][j].num_like = 0;
                classroom[i][j].target = true; // 초기화 필요한 항목을 확실히 파악해야한다.
            }
        }
    }
}

void set_adj_info(student s, int r, int c) {
    bool flag = false;

    for(int i = 0; i < DIRECTION_NUM; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(0 <= nr&&nr < n && 0 <= nc&&nc < n) {
            for(auto l: s.like_arr) {
                if(classroom[nr][nc].num == l) {
                    classroom[r][c].num_like++; // 비교는 인접 항목과 수행하지만, 값 반영은 현재 위치에 해야한다.
                    flag = true;
                    if(LOG) cout << "(" << nr << ", " << nc << ") count like!!" << endl;
                }
            }
            if(classroom[nr][nc].num == -1) {
                classroom[r][c].num_blank++;
                flag = true;
                if(LOG) cout << "(" << nr << ", " << nc << ") count blank!!" << endl;
            }
        }
    }

    if(flag) classroom[r][c].target = true;
}

void find_blank(student s) {
    if(LOG) cout << "find_blank(num=" << s.num << ")" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(classroom[i][j].num != -1) continue;
            set_adj_info(s, i, j);
        }
    }
}

void cond3(student s) {
    if(LOG) cout << "cond3()" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(classroom[i][j].target == false) continue;
            classroom[i][j].num = s.num;
            classroom[i][j].num_blank = 0;
            classroom[i][j].num_like = 0;
            classroom[i][j].target = false;
            return;
        }
    }
}

void cond2(student s) {
    if(LOG) cout << "cond2()" << endl;
    int max_blank = 0;
    bool dup = false;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(classroom[i][j].target == false) continue;
            if(max_blank < classroom[i][j].num_blank) {
                max_blank = classroom[i][j].num_blank;
                dup = false;
            }
            else if(max_blank == classroom[i][j].num_blank) {
                dup = true;
            }
        }
    }

    if(dup == true) {
        // 선택받은 애들 제외하고는 비활성화 해야한다.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j].num_blank != max_blank) {
                    classroom[i][j].target = false;
                }
            }
        }

        if(LOG) print_classroom();

        // 조건 2 확인
        cond3(s);
    }
    else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j].target == false) continue;   // 조건에 맞는 경우에도 target이 아닌 학생은 skip 해야한다.
                if(classroom[i][j].num_blank != max_blank) continue;
                classroom[i][j].num = s.num;
                classroom[i][j].num_blank = 0;
                classroom[i][j].num_like = 0;
                classroom[i][j].target = false;
                return;
            }
        }
    }
}

void cond1(student s) {
    if(LOG) cout << "cond1()" << endl;
    int max_like = 0;
    bool dup = false;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // if(classroom[i][j].target == false) continue;   // 이거는 없어도 괜찮지 않나? 왜 이 조건이 필수지?
                                                            // 새로운 최신값을 만났을 때 dup 초기화를 해줘야하는데 이 조건이 있으면 테케에서 회피하는거같다.
            if(max_like < classroom[i][j].num_like) {
                max_like = classroom[i][j].num_like;
                dup = false;
            }
            else if(max_like == classroom[i][j].num_like) {
                dup = true;
            }
        }
    }

    if(dup == true) {
        // 선택받은 애들 제외하고는 비활성화 해야한다.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j].num_like != max_like) {
                    classroom[i][j].target = false;
                }
            }
        }

        if(LOG) print_classroom();

        // 조건 2 확인
        cond2(s);
    }
    else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j].target == false) continue;
                if(classroom[i][j].num_like != max_like) continue;
                classroom[i][j].num = s.num;
                classroom[i][j].num_blank = 0;
                classroom[i][j].num_like = 0;
                classroom[i][j].target = false;
                return;
            }
        }
    }
}

int get_score() {
    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            student s;
            for(int si = 0; si < n*n; si++) {
                if(classroom[i][j].num == s_arr[si].num) {
                    s = s_arr[si];
                    break;
                }
            }

            for(int di = 0; di < DIRECTION_NUM; di++) {
                int nr = i + dr[di];
                int nc = j + dc[di];

                if(0 <= nr&&nr < n && 0 <= nc&&nc < n) {
                    for(auto l: s.like_arr) {
                        if(classroom[nr][nc].num == l) {
                            classroom[i][j].num_like++; // 비교는 인접 항목과 수행하지만, 값 반영은 현재 위치에 해야한다.
                        }
                    }
                }
            }

            int num = classroom[i][j].num_like;
            if(num == 1) ans++;
            else if(num == 2) ans += 10;
            else if(num == 3) ans += 100;
            else if(num == 4) ans += 1000;
        }
    }

    return ans;
}

void solution() {
    // 첫 학생은 1, 1 자리에 확정이다.
    set_first_seat();
    
    for(int i = 0; i < n*n; i++) {
        student s = s_arr[i];

        // 선호도와 빈 자리를 조사한 2차원 배열의 내용 중 일부를 초기화한다.
        init();

        // 첫 값은 이미 설정했으니 skip한다.
        if(s.num == s_arr[0].num) continue;

        // 각 빈칸에 like, blank 정보 담기 (매번 초기화 후 담아야한다. 아니면 어차피 num이 -1인 애들만 갱신하니까 상관없나?)
        // 조건 대상 여부 관리 <- 조건을 거치며 대상에서 제외할 수 있어야 하기 때문
        find_blank(s);

        if(LOG) print_classroom();

        // 조건 1 확인
        cond1(s);

        if(LOG) cout << "After condi!!" << endl;
        if(LOG) print_classroom();
    }

    cout << get_score() << endl;

    if(LOG) print_classroom();
}

void solve() {
    input();
    solution();
}

int main() {
    solve();
    return 0;
}