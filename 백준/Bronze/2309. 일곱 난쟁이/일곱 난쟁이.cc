#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v;
    for(int i=0;i<9;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    // 2개씩 빼고 계산해서 100이면 정답?

    bool flag=false;
    int sum=0;
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            for(int k=0;k<9;k++){
                if(k!=i&&k!=j)
                    sum+=v[k];
            }
            if(sum==100){
                v.erase(v.begin()+i);
                v.erase(v.begin()+j-1); // 인덱스 당겨지기 때문에 -1 해줘야함
                flag=true;
                break;
            }
            sum=0;
        }
        if(flag) break;
    }

    sort(v.begin(), v.end());
    
    for(int i=0;i<7;i++){
        cout<<v[i]<<endl;
    }
    
    return 0;
}
