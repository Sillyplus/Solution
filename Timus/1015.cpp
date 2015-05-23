/*******************************************************************************
	> File Name: 1015.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu May 21 12:47:15 2015
*******************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > ans;
int f[7][7][7][7][7][7] = {0};

int main() {
    int n, a1, a2, a3, a4, a5, a6, total = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6);
        if (f[a1][a2][a3][a4][a5][a6] == 0) {
            total++;
            vector<int> tmp;
            tmp.push_back(i);
            ans.push_back(tmp);
            f[a1][a2][a3][a4][a5][a6] = total;
            f[a1][a2][a4][a5][a6][a3] = total;
            f[a1][a2][a5][a6][a3][a4] = total;
            f[a1][a2][a6][a3][a4][a5] = total;
            f[a2][a1][a3][a6][a5][a4] = total;
            f[a2][a1][a4][a3][a6][a5] = total;
            f[a2][a1][a5][a4][a3][a6] = total;
            f[a2][a1][a6][a5][a4][a3] = total;
            f[a3][a5][a2][a4][a1][a6] = total;
            f[a3][a5][a6][a2][a4][a1] = total;
            f[a3][a5][a1][a6][a2][a4] = total;
            f[a3][a5][a4][a1][a6][a2] = total;
            f[a5][a3][a1][a4][a2][a6] = total;
            f[a5][a3][a6][a1][a4][a2] = total;
            f[a5][a3][a2][a6][a1][a4] = total;
            f[a5][a3][a4][a2][a6][a1] = total;
            f[a4][a6][a3][a2][a5][a1] = total;
            f[a4][a6][a1][a3][a2][a5] = total;
            f[a4][a6][a5][a1][a3][a2] = total;
            f[a4][a6][a2][a5][a1][a3] = total;
            f[a6][a4][a5][a2][a3][a1] = total;
            f[a6][a4][a1][a5][a2][a3] = total;
            f[a6][a4][a3][a1][a5][a2] = total;
            f[a6][a4][a2][a3][a1][a5] = total;
        } else {
            ans[f[a1][a2][a3][a4][a5][a6] - 1].push_back(i);
        }
    }
    cout << total << endl;
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
