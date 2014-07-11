#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    long long ans = 1;
    for (int i = n; i > 0; i -= s.length())
        ans *= i;
    cout << ans << endl;
    return 0;
}
