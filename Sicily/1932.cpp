#include <iostream>
#include <stack>

using namespace std;
int f[200010];

int main(){
    int n, t;
    cin >> t;
    while (t--) {
        stack<int> s;
        int a, b;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a >> b;
            f[a] = f[b] = i;
        }
        for (int i = 1; i <= 2*n; i++) {
            if (!s.empty() && s.top() == f[i])
                s.pop();
            else
                s.push(f[i]);
        }
        if (s.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
