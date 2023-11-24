#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long Find(unordered_map<long long, long long>& m, long long n) {
    if(m[n]==0) return n;
    return m[n] = Find(m, m[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    unordered_map<long long, long long> room_rec;
    
    for(int i = 0; i < room_number.size(); ++i) {
        long long book = room_number[i];
        
        if(room_rec[book] == 0) {
            answer.push_back(book);
            room_rec[book] = Find(room_rec, book+1);
        }
        else {
            long long nn = Find(room_rec, book);
            answer.push_back(nn);
            room_rec[nn] = Find(room_rec, nn+1);
        }
    }
    
    return answer;
}