#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int a[100];
bool f[810][810];

double mi(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

bool check(int a, int b, int c) {
    if (a+b <= c) return false;
    if (a+c <= b) return false;
    if (b+c <= a) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n) {
        int sum = 0;
        for (int i = 0; i < n ; i++) {
            cin >> a[i];
            sum += a[i];
        }
        memset(f, false, sizeof(f));
        f[0][0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = sum/2; j >= 0; j--)
                for (int k = j; k >= 0; k--)
                    if((j >= a[i] && f[j-a[i]][k]) || (k >=a[i] && f[j][k-a[i]]))
                        f[j][k]=1;
        double ans = 0;
        for (int i = 1; i <= sum/2; i++)
            for (int j = 1; j <= sum/2; j++) {
                if(f[i][j] && check(i, j, sum-i-j))
                    ans = max(ans, mi(i, j, sum-i-j));
            }
        if (ans == 0)
            cout << "-1\n";
        else
            cout << (int)(ans*1000)/10 << endl;
        cin >> n;
    }
    return 0;
}
