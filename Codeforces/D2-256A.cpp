#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MN = 10010;

int a1, a2, a3;
int b1, b2, b3;
int n, a, b, ans;


int main() {
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    cin >> n;
    a = a1 + a2 + a3;
    b = b1 + b2 + b3;
    ans = 0;
    ans = ans + (a % 5 == 0 ? (a/5): (a/5)+1);
    ans = ans + (b % 10 == 0 ? (b/10): (b/10)+1);
    if (ans <= n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
