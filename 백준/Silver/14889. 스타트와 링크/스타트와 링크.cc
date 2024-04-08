#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define LOG false

int n;
vector<vector<int>> v;

int min_val = INT_MAX;

void input() {
    cin >> n;

    v.resize(n);
    for(int i = 0; i < n; i++) {
        int a;
        for(int j = 0; j < n; j++) {
            cin >> a;
            v[i].push_back(a);
        }
    }
}

void print(vector<int> team, string name) {
    cout << "print(" << name << ")" << endl;
    for(int i = 0; i < team.size(); i++) {
        cout << team[i] << " ";
    }
    cout << endl;
}

int score_diff(vector<int> team1, vector<int> team2) {
    if(LOG) cout << "score_diff();" << endl;
    int sum1 = 0;
    int sum2 = 0;

    for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < n/2; j++) {
            sum1 += v[team1[i]][team1[j]];
            sum2 += v[team2[i]][team2[j]];
        }
    }

    return abs(sum1 - sum2);
}

void matching(vector<int> team1, vector<int> team2, int num) {
    if(LOG) cout << "matching(num= " << num << ");" << endl;
    if(num >= n) {
        if(!(team1.size() >= n/2 && team2.size() >= n/2)) return;
        if(LOG) print(team1, "team1");
        if(LOG) print(team2, "team2");
        int ans = score_diff(team1, team2);
        if(LOG) cout << "score_dff: " << ans << endl;
        if(min_val > ans) {
            min_val = ans;
            if(LOG) cout << "min_val: " << min_val << endl;
        }
        return;
    }
    
    team1.push_back(num);
    matching(team1, team2, num+1);
    team1.pop_back();
    team2.push_back(num);
    matching(team1, team2, num+1);
    team2.pop_back();
}

void solution() {
    vector<int> tmpv;
    matching(tmpv, tmpv, 0);

    cout << min_val;
}

void solve() {
    input();
    solution();
}

int main() {
    solve();

    return 0;
}