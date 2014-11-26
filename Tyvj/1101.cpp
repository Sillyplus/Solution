#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10010;

string a[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
    return 0;
}
