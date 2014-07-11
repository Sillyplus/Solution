#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int MN = 110;

int n, m, tot;
int mp1[MN][MN] = {0};
int mp2[MN][MN] = {0};
int from[MN*MN] = {0};
vector<int> g[MN*MN];
bool use[MN*MN];

bool match(int x) {
    for (int i = 0; i < g[x].size(); i++)
        if (!use[g[x][i]]) {
            use[g[x][i]] = true;
            if (from[g[x][i]] == -1 || match(from[g[x][i]])) {
                from[g[x][i]] = x;
                return true;
            }
        }
    return false;
}

int hungary() {
    tot = 0;
    memset(from, 255, sizeof(from));
    for (int i = 0; i < n*m; i++) {
        memset(use, 0, sizeof(use));
        if (match(i)) tot++;
    }
    return tot;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &mp1[i][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if ((i+j)%2 != 0) {
            if ((j+1 < m) && (mp1[i][j] != mp1[i][j+1]))
                g[i*m+j].push_back(i*m+j+1);
            if ((i+1 < n) && (mp1[i][j] != mp1[i+1][j]))
                g[i*m+j].push_back((i+1)*m+j);
            if ((j-1 >= 0) && (mp1[i][j] != mp1[i][j-1]))
                g[i*m+j].push_back(i*m+j-1);
            if ((i-1 >= 0) && (mp1[i][j] != mp1[i-1][j]))
                g[i*m+j].push_back((i-1)*m+j);
        }
    }

    int ans = 0;
    ans = hungary();
    if (ans == (n*m/2)) {
        memset(mp2, 255, sizeof(mp2));
        int k = 0;
        for (int i = 0; i < n*m; i++)
            if (from[i] != -1) {
                k++;
                mp2[from[i]/m][from[i]%m] = k;
                mp2[i/m][i%m] = k;
            }
        for (int i = 0; i< n; i++) {
            printf("%d", mp2[i][0]);
            for (int j = 1; j < m; j++)
                printf(" %d", mp2[i][j]);
            cout << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}
