#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calc(long long a, long long b, char op) {
    if(op=='+') return a+b;
    else if(op=='-') return a-b;
    else if(op=='*') return a*b;
}

long long solution(string expression) {
    long long answer = 0;
    
    // expression을 숫자와 연산자로 구분.
    vector<long long> origin_operand;
    vector<char> origin_operator;
    
    string tmp = "";
    for(int i = 0; i < expression.length(); ++i) {
        if('0'<=expression[i]&&expression[i]<='9') {
            tmp += expression[i];
        }
        else {
            origin_operand.push_back(stoi(tmp));
            tmp="";
            origin_operator.push_back(expression[i]);
        }
    }
    origin_operand.push_back(stoi(tmp));
    
    // 연산자 우선순위 순열 돌리고, 각 우선순위에 따른 연산 진행
    vector<int> perm = {0, 1, 2};
    string op = "+-*";
    
    do {
        vector<long long> tmp_operand = origin_operand;
        vector<char> tmp_operator = origin_operator;
        
        // 연산자 우선순위 순서대로
        for(int i = 0; i < op.length(); ++i) {
            for(int j = 0; j < tmp_operator.size(); ++j) {
                if(op[perm[i]]==tmp_operator[j]) {
                    long long res = calc(tmp_operand[j], tmp_operand[j+1], tmp_operator[j]);
                    tmp_operand.erase(tmp_operand.begin()+j);
                    tmp_operand.erase(tmp_operand.begin()+j);
                    tmp_operand.insert(tmp_operand.begin()+j, res);
                    
                    tmp_operator.erase(tmp_operator.begin()+j);
                    
                    j--;
                }
            }
        }
        
        answer = max(answer, abs(tmp_operand[0]));
        
    } while(next_permutation(perm.begin(), perm.end()));
    
    return answer;
}