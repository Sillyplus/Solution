#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int>::iterator its;

int ds(int x) {
    int ret = 0;
    while (x) {
        ret += (x % 10);
        x /= 10;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    while (n) {
        v.push_back(n);
        n -= ds(n);
    }
    cout << v.size() << endl;
    for (its = v.begin(); its != v.end(); its++)
        cout << *its << ' ';
    cout << endl;
    return 0;
}
