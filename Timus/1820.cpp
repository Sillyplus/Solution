#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << (n<k?2:2*n%k?2*n/k+1:2*n/k);
    return 0;
}
