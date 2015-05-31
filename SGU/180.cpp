/*******************************************************************************
	> File Name: 180.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat May 30 21:28:12 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 66000;

long long inversed_pair(int a[], int n) {
    if (n == 1) return 0;
    long long sum = 0;
    int mid = n / 2;
    sum += inversed_pair(a, mid);
    sum += inversed_pair(a+mid, n-mid);
    int *b = new int[n];
    memcpy(b, a, n * sizeof(int));
    for (int i1 = 0, i2 = mid, i = 0; i1 < mid || i2 < n; ++i) {
        if (i2 == n) {
            a[i] = b[i1++];
            sum += i2 - mid;
        } else if (i1 == mid) {
            a[i] = b[i2++];
        } else if (b[i1] < b[i2]) {
            a[i] = b[i1++];
            sum += i2 - mid;
        } else {
            a[i] = b[i2++];
        }
    }
    delete [] b;
    return sum;
}

int f[MAXN];

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", f+i);
    }
    long long ans = inversed_pair(f, n);
    long long tmp = 1;
    f[n] = -1;
    for (int i = 1; i <= n; ++i) {
        if (f[i] != f[i-1]) {
            ans = ans - (tmp * (tmp-1) / 2);
            tmp = 1;
        } else tmp++;
    }
    cout << ans << endl;
    return 0;
}
