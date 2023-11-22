#include <string>
#include <vector>

#include <regex>

using namespace std;

// vector<string> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
//     long long answer = 0;
    
//     bool is_matched=true;
    
//     for(int idx_s = 0; idx_s < s.length(); ++idx_s) {
//         if('0'<=s[idx_s]&&s[idx_s]<='9') {
//             answer+=s[idx_s]-'0';
//             answer*=10;
//             continue;
//         }
//         for(int i = 0; i < words.size(); ++i) {
//             is_matched=true;
//             for(int j = 0; j < words[i].length(); ++j) {
//                 if(s[idx_s+j] != words[i][j]) {
//                     is_matched=false;
//                     break;
//                 }
//             }
//             if(is_matched==true) {
//                 answer+=i;
//                 answer*=10;
                
//                 idx_s+=words[i].length()-1;
//             }
//         }
//     }
    
//     answer/=10;
    
    // 풀이 2
    int answer=0;
    
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");
    
    answer = stoi(s);
    
    return answer;
}