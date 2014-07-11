#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) q.push(i);
        for (int i = 1; i <= n; i++) {
            cout << q.front() << " ";
            q.pop();
            if (q.empty() != true) {
                x = q.front();
                q.pop();
                q.push(x);
            }
        }
        cout << endl;
    }
    return 0;
}
