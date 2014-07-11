#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    int n;
    long long sum, x;
    for (int i = 0; i < t; i++) {
        cin >> n;
        sum = 0;
        for (int j = 0; j < n; j++) {
            cin >> x;
            sum += x*x;
        }
        cout << sum << endl;
    }
    return 0;
}
