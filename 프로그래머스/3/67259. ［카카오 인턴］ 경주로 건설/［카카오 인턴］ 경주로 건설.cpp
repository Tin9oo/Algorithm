#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

struct task {
    int x;
    int y;
    int price;
    int dir;
};

vector<int> dx={0, 1, 0, -1};
vector<int> dy={1, 0, -1, 0};

int solution(vector<vector<int>> board) {
    int answer = INT_MAX;
    
    int N = board.size();
    
    vector<vector<vector<int>>> cost_board(N, vector<vector<int>>(N, vector<int>(4, INT_MAX)));
    for(int i = 0; i < dx.size(); ++i) cost_board[0][0][i]=0;
    
    queue<task> q;
    q.push({0, 0, 0, -1});
    
    while(!q.empty()) {
        task t = q.front();
        q.pop();
        int cp = t.price;
        int cd = t.dir;
                
        for(int i = 0; i < dx.size(); ++i) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            
            if(0<=nx&&nx<N && 0<=ny&&ny<N && board[nx][ny]==0) {
                int np;
                if(cd==-1 || cd==i) np = cp + 100;
                else if(cd != i) {
                    np = cp + 600;
                }
                
                if(cost_board[nx][ny][i] > np) { // 같은 경우도 확인해야 완전탐색이다.
                    cost_board[nx][ny][i] = np;
                    q.push({nx, ny, np, i});
                }
            }
        }
    }
    
    return *min_element(cost_board[N-1][N-1].begin(), cost_board[N-1][N-1].end());
}