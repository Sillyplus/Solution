#include <iostream>
#include <stack>

using namespace std;

stack<int> a;
stack<int> b;
int c[10000];

int main() {
    int n;
    cin >> n;
    while (1) {
        cin >> c[0];
        while (c[0] != 0) {
            int cnt = 1;
            bool flag = true;
            while (!b.empty()) b.pop();
            for (int i = 1; i < n; i++)
                cin >> c[i];
            for (int i = 0; i < n; i++) {
                if (c[i] == cnt) {
                    cnt++;
                } else if (!b.empty() && c[i] == b.top()) {
                    b.pop();
                } else if (c[i] > cnt) {
                    while (c[i] != cnt && cnt < n) {
                        b.push(cnt);
                        cnt++;
                    }
                    if (c[i] == cnt) {
                        cnt++;
                    } else {
                        flag = false;
                    }
                } else {
                    flag = false;
                }
                if (!flag) {
                    break;
                }
            }
            if (flag)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            cin >> c[0];
        }
        cout << endl;
        cin >> n;
        if (!n)
            break;
    }
    return 0;
}
