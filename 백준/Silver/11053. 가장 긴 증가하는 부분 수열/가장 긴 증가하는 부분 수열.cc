#include <iostream>
#include <vector>

using namespace std;

#define LOG true

vector<int> lis;

int bs(int left, int right, int ele) {
    int mid;

    while(left < right) {
        mid = (left + right) / 2;

        if(lis[mid] < ele) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return right;
}

int main() {
    int answer = 0;

    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    lis.push_back(vec[0]);
    for(int i = 1; i < n; i++) {
        if(lis.back() < vec[i]) {
            lis.push_back(vec[i]);
        }
        else {
            int idx = bs(0, lis.size(), vec[i]);
            lis[idx] = vec[i];
        }
    }

    cout << lis.size();

    return 0;
}