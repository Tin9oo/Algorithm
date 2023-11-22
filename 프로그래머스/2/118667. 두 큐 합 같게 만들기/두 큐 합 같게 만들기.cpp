#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    queue<int> q1, q2;
    
    int q1s=queue1.size();
    int q2s=queue2.size();
    int qs = q1s+q2s;
    
    for(int i = 0; i < q1s; ++i) {
        q1.push(queue1[i]);
    }
    for(int i = 0; i < q2s; ++i) {
        q2.push(queue2[i]);
    }
        
    long a=0, b=0;
    queue<int> q1t=q1, q2t=q2; // 큐의 합은 복사본으로 구해야한다.
    while(!q1t.empty()) {
        a+=q1t.front();
        q1t.pop();
    }
    while(!q2t.empty()) {
        b+=q2t.front();
        q2t.pop();
    }
    
    int is_not_same;
    if(a>b) is_not_same=1;
    else if(a==b) is_not_same=0;
    else if(a<b) is_not_same=-1;
    
    int idx=0;
    int tmp;
    while(is_not_same!=0) {
        if(idx > 4*qs) {
            // cout << "No more chance!!" << endl;
            answer=-1;
            break;
        }
        
        // cout << "a: " << a << ", b: " << b << endl;
        
        if(is_not_same==1) {
            // cout << "q1 sum is larger" << endl;
            tmp=q1.front();
            // cout << "tmp: " << tmp << endl;
            q2.push(tmp);
            q1.pop();
            a-=tmp;
            b+=tmp;
            answer++;
        }
        else if(is_not_same==-1) {
            // cout << "q2 sum is larger" << endl;
            tmp=q2.front();
            // cout << "tmp: " << tmp << endl;
            q1.push(tmp);
            q2.pop();
            a+=tmp;
            b-=tmp;
            answer++;
        }
        
        if(a>b) is_not_same=1;
        else if(a==b) is_not_same=0;
        else if(a<b) is_not_same=-1;
        
        idx++;
    }
    
    return answer;
}