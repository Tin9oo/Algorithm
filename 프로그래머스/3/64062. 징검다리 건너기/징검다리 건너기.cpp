#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool can_jump(vector<int> stones, int k, int mid) {
    int jump=0;
    for(auto st: stones) {
        if(st < mid) {
            jump++;
        }
        else {
            jump=0;
        }
        if(jump >= k) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    if(k==1) {
        answer = *min_element(stones.begin(), stones.end());
        return answer;
    }
    
    int idx_l = 1;
    int idx_r = *max_element(stones.begin(), stones.end());
    
    int mid;
    
    while(idx_l < idx_r-1) {
        mid = (idx_l + idx_r) / 2;
        if(can_jump(stones, k, mid)) {
            idx_l = mid;
        }
        else {
            idx_r = mid;
        }
    }
    
    answer = idx_l;
    
    return answer;
}