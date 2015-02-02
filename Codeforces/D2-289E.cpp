/*******************************************************************************
	> File Name: D2-289E.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Jan 31 21:22:01 2015
 ******************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 500000 + 100;

string s;
long long sum[MAXN], sum2[MAXN];

int main() {
    cin >> s;
    int n = s.size();
    memset(sum, 0, sizeof(sum));
    memset(sum2, 0, sizeof(sum2));
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
            sum[i+1] = 1 + sum[i];
        } else {
            sum[i+1] = sum[i];
        }
        sum2[i+1] += sum2[i] + sum[i+1];
    }
    double ans = 0.0;
    for (int i = 1; i <= n; i++) {
        ans += (sum2[n] - sum2[n-i] - sum2[i-1])*1.0 / i; 
    }
    printf("%.8f\n", ans);
    return 0;
}
