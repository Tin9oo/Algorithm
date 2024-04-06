#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<pair<int, int>> v, int level, int profit);

int max_profit=0;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // for(int i = 0; i < n; i++) {
    //     cout << "[" << v[i].first << ", " << v[i].second << "]\n";
    // }

    dfs(v, 0, 0);

    cout << max_profit;

    return 0;
}

void dfs(vector<pair<int, int>> v, int level, int profit) {
    if(level > v.size()-1) {    // 벡터 길이만큼 돌리면 segmentation error 발생함.
                                // 길이-1만큼 돌려야 7부터 멈추는게 맞다.
        // cout << "dfs(v, " << level << ", " << profit << ")" << endl;;
        if(level == v.size() && max_profit < profit) { // 벡터 길이 넘은 애들 중에 길이에 딱 맞는 애들만 유효한 값임.
            max_profit = profit;
        }
        return;
    }

    dfs(v, level+v[level].first, profit+v[level].second);
    dfs(v, level+1, profit);

    return;
}