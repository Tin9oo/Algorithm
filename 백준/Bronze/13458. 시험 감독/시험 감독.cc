#include <iostream>
#include <vector>

using namespace std;

// 총감독관은 1명 꼭 있어야한다.

int main() {
    int a;
    cin >> a;

    vector<int> v = vector<int>(a,0);
    for(int i = 0; i < a;i++) {
        cin >> v[i];
    }
    int b, c;
    cin >> b >> c;

    for(int i = 0; i < a; i++) {
        v[i] -= b;
        // 음수가 되는 경우 0으로 맞춰준다.
        if(v[i]<0) v[i]=0;
    }

    long cnt=0; // 최댓값으로 입력되면 오버플로우 발생 가능
    for(int i = 0; i < a; i++) {
        cnt+=v[i]/c;
        if(v[i]%c!=0) cnt++;
    }

    cout << a+cnt;

    return 0;
}