/*******************************************************************************
	> File Name: 1090.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon May 18 22:50:15 2015
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 10010;
typedef long long LL;

int f[MAXN] = {0};

LL inversed_pair(int a[], int n) {
    if (n == 1) return 0;
    LL sum = 0;
    int mid = n / 2;
    sum += inversed_pair(a, mid);
    sum += inversed_pair(a + mid , n - mid);
    int *b = new int[n];
    memcpy(b, a, n * sizeof(int));
    for (int i1 = 0, i2 = mid, i = 0; i1 < mid || i2 < n; i++) {
        if (i2 == n) {
            a[i] = b[i1];
            i1++;
            sum += i2 - mid;
        } else if (i1 == mid) {
            a[i] = b[i2];
            i2++;
        } else if (b[i1] < b[i2]) {
            a[i] = b[i1];
            i1++;
            sum += i2 - mid;
        } else {
            a[i] = b[i2];
            i2++;
        }
    }
    delete [] b;
    return sum;
}

int main() {
    int n, k;
    int ans = -1;
    LL temp = -1;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &f[j]);
        }
        LL temp2 = inversed_pair(f, n);
        if (temp < temp2) {
            ans = i;
            temp = temp2;
            
        }
    }
    cout << ans+1 << endl;
    return 0;
}
