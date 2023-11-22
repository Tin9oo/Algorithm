#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
//     int gatcha=0;
//     string s;
    
//     for(int i = 0; i < moves.size(); ++i) {
//         for(int j = 0; j < board.size(); ++j) {
//             if(board[j][moves[i]-1]!=0) {
//                 s+=to_string(board[j][moves[i]-1]);
//                 s+=' ';
//                 board[j][moves[i]-1]=0;
//                 break;
//             }
//         }
//     }
    
//     while(true) {
//         bool is_pair=false;
//         for(int j = 100; j > 0; --j) {
//             string tmp; tmp+=to_string(j)+' '; tmp+=to_string(j)+' ';
            
//             if(regex_search(s, regex(tmp))) {
//                 s=regex_replace(s, regex(tmp), "");    
//                 answer+=2;
//                 is_pair=true;
//             }
//         }
//         if(is_pair==false) break;
//     }
    
    stack<int> bucket;
    
    for(auto move: moves) {
        for(auto i = 0; i < board.size(); ++i) {
            int doll = board[i][move-1];
            board[i][move-1]=0;
            if(doll!=0) {
                if(!bucket.empty()) {
                    if(bucket.top()==doll) {
                        bucket.pop();
                        answer+=2;
                        break;
                    }
                }
                bucket.push(doll);
                break;
            }
        }
    }
    
    return answer;
}