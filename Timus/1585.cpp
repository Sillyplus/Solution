#include <iostream>

using namespace std;

char c[30];

int main() {
    int n;
    int e, m, l;
    e = m = l = 0;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++) {
        cin.getline(c, 30);
        if (c[0] == 'E')
            e++;
        else if (c[0] == 'L')
            l++;
        else
            m++;
    }
    if (e > m && e > l) {
        cout << "Emperor Penguin" << endl;
    } else if (m > e && m > l) {
        cout << "Macaroni Penguin" << endl;
    } else {
        cout << "Little Penguin" << endl;
    }
    return 0;
}
