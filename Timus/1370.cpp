/*******************************************************************************
	> File Name: 1370.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jan 13 14:13:30 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

const int MAXN = 2010;
int a[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for (int i = m % n + 1; i < m % n + 11; i++)
        cout << a[i];
    cout << endl;
    return 0;
}
