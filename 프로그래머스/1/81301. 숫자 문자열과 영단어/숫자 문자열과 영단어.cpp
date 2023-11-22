#include <string>
#include <vector>

using namespace std;

vector<string> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    long long answer = 0;
    
    bool is_matched=true;
    
    for(int idx_s = 0; idx_s < s.length(); ++idx_s) {
        if('0'<=s[idx_s]&&s[idx_s]<='9') {
            answer+=s[idx_s]-'0';
            answer*=10;
            continue;
        }
        for(int i = 0; i < words.size(); ++i) {
            is_matched=true;
            for(int j = 0; j < words[i].length(); ++j) {
                if(s[idx_s+j] != words[i][j]) {
                    is_matched=false;
                    break;
                }
            }
            if(is_matched==true) {
                answer+=i;
                answer*=10;
                
                idx_s+=words[i].length()-1;
            }
        }
    }
    
    answer/=10;
    
    return answer;
}