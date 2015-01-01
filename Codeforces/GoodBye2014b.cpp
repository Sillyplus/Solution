/*******************************************************************************
	> File Name: b.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Dec 30 23:26:50 2014
 ******************************************************************************/

#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

const int MAXN = 310;

int a[MAXN];
char c[MAXN][MAXN];
bool v[MAXN];
map<int, int> mp;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
        scanf("%s", c[i]); 
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (c[i][k] == '1' && c[k][j] == '1')
                    c[i][j] = '1';
    map<int, int>::iterator its;
    memset(v, false, sizeof(v));
    for (its = mp.begin(); its != mp.end(); its++) {
        for(int i = 0; i < n; i++) {
            if (c[its->second][i] == '1' && !v[i]) {
                v[i] = true;
                mp[a[i]] = its->second;
                int tmp = a[i];
                a[i] = a[its->second];
                a[its->second] = tmp;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    cout << endl;
    return 0;
}
