#include <iostream>
#include <deque>
#include <climits>

using namespace std;

#define N_MAX 11

int n;
deque<int> nums;
deque<int> op;

int min_val = INT_MAX;
int max_val = INT_MIN;

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        nums.push_back(a);
    }
    for(int i = 0; i < 4; i++) {
        int a; cin >> a;
        op.push_back(a);
    }
}

void calculate(deque<int> tmpnums, deque<int> tmpop, int ans) {
    if(tmpnums.empty()) {
        if(min_val > ans) min_val = ans;
        if(max_val < ans) max_val = ans;
        // cout << "min: " << min_val << endl;
        // cout << "max: " << max_val << endl;
        return;
    }

    int operand = tmpnums.front(); // 위에서 return 하지않으면, 이미 비어있는 deque의 front를 호출하려해서 오류 발생
    tmpnums.pop_front();

    if(tmpop[0] > 0) { // +
        tmpop[0]--;
        calculate(tmpnums, tmpop, ans + operand);
        tmpop[0]++;
    }
    if(tmpop[1] > 0) {// -
        tmpop[1]--;
        calculate(tmpnums, tmpop, ans - operand);
        tmpop[1]++;
    }
    if(tmpop[2] > 0) {// *
        tmpop[2]--;
        calculate(tmpnums, tmpop, ans * operand);
        tmpop[2]++;
    }
    if(tmpop[3] > 0) { // /
        tmpop[3]--;
        calculate(tmpnums, tmpop, ans / operand);
        tmpop[3]++;
    }
}

void solution() {
    int ans = nums.front();
    nums.pop_front();
    calculate(nums, op, ans);

    cout << max_val << endl << min_val;
}

void solve() {
    input();
    solution();
}

int main() {
    solve();

    return 0;
}