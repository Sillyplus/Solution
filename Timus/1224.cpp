#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, ans = 0;;
    cin >> n >> m;
    cout << min(2*(n-1), 2*(m-1)+1) << endl;
    return 0;
}
