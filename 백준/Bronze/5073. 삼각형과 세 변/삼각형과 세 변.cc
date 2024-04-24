#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int a, b, c;
    int max;

    while (true) {
        cin >> a >> b >> c;

        if(a==0&&b==0&&c==0) break;

        if(a < b) {
            if(b < c) {
                max = c;
            } else {
                max = b;
            }
        }
        else {
            if(a < c) {
                max = c;
            }
            else {
                max = a;
            }
        }

        if(max >= (a+b+c)-max) {
            cout << "Invalid" << endl;
            continue;
        }

        if(a==b && b==c) {
            cout << "Equilateral" << endl;
        }
        else if(a==b || a==c || b==c) {
            cout << "Isosceles" << endl;
        }
        else if(a!=b && b!=c && a!=c) {
            cout << "Scalene" << endl;
        }
    }

    return 0;
}