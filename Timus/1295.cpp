#include <iostream>

using namespace std;

int ans[20] = {0,1,1,2,0,2,1,2,0,1,1,2,0,1,1,2,0,1,1,2};

int main() {
    int n;
    cin >> n;
    n %= 20;
    cout << ans[n] << endl;
    return 0;
}
