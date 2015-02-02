/*******************************************************************************
	> File Name: D2-289B.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Jan 31 20:15:57 2015
 ******************************************************************************/

#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 110;

map<int, int> m;

int d[MAXN][MAXN];

struct pile{
    int id, cp;
};

pile a[MAXN];

bool comp(const pile &x, const pile &y) {
    return x.cp < y.cp;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].cp;
        a[i].id = i;
    }

    sort(a, a+n, comp);
    for (int i = 0; i < n; i++)
        m[a[i].id] = i;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = 0;
    
    for (int i = 0; i < k; i++)
        d[0][i] = a[0].cp / k;
    for (int i = 0; i < (a[0].cp % k); i++)
        d[0][i]++;
    
    for (int i = 1; i < n; i++) {
        for (int c = 0; c < k; c++)
            d[i][c] = a[i].cp / k;
        for (int c = 0; c < (a[i].cp % k); c++)
            d[i][c]++;
    
        for (int j = 0; j < i; j++) {
            for (int c = 0; c < k; c++) {
                if (abs(d[i][c] - d[j][c]) > 1) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int x = 0; x < d[m[i]][j]; x++)
                printf("%d ", j+1);
        }        
        cout << endl;
    }

    return 0;
}
