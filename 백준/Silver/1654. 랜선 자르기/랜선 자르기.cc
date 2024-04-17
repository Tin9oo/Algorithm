#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// 1시간 15분 실패
// 최초에 전체 탐색해서 시간초과 발생
// 이분 탐색으로 시간복잡도 log로 만들어 시간초과 해결했으나, 문제는 틀림


// Abstract =====
// K개의 랜선을 잘라서 같은 길이의 N개 랜선으로 만들어야한다.
// 편의상, 정답은 반드시 있다고 가정.
// N개보다 많이 만드는 것도 N개 만드는 것에 포함된다.
// 이 때 만들 수 있는 랜선의 최대 길이를 구하라.

// 랜선 길이는 2^31 - 1 보다 작거나 같은 자연수 <= 20억 정도 되네

#define LOG false

int k, n; // 100만 이하
vector<int> lan_arr;

int answer = INT_MIN;

void input() {
    cin >> k >> n;

    lan_arr.resize(k);
    for(int i = 0; i < k; i++) {
        cin >> lan_arr[i];
    }
}

void solution() {
    long i = 1;
    long j = *max_element(lan_arr.begin(), lan_arr.end());
    
    // 최대 길이부터 늘려가며 반복
    while(i <= j) {
        
        long mid = (j + i) / 2; // 이거 더하면 오버플로우 발생하나?
        int max_lan_num = 0;
        
        if(LOG) cout << "i = " << i << ", mid = " << mid << ", j = " << j << endl;

        // 주어진 랜선을 잘라서 해당 길이에 맞는 수 만큼 카운트
        if(LOG) cout << "max_lan_num : ";
        for(auto l: lan_arr) {
            max_lan_num += l / mid;
            if(LOG) cout << max_lan_num << " ";
        }
        if(LOG) cout << endl;

        // 랜선 개수 부족하면
        if(max_lan_num < n) {
            j = mid - 1;
        }

        // 랜선의 개수가 n개를 넘고 && 랜선 길이가 최대인 경우
        if(max_lan_num >= n) {
            if(answer < mid) {
                answer =  mid;
                if(LOG) cout << "answer is updated to " << answer << endl;
            }
            i = mid + 1;
        }
        if(LOG) cout << endl;
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