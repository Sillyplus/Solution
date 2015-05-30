/*******************************************************************************
	> File Name: LAZYPROG.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat May 30 00:08:21 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const double EXP = 1e-6;

struct jobs {
    double a, b, d, tx;

    bool operator < (const jobs &x) const {
        return a < x.a;
    }
};

bool cmp(const jobs &x, const jobs &y) {
    return x.d < y.d;
}

jobs f[MAXN];

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf%lf", &f[i].a, &f[i].b, &f[i].d);
            f[i].tx = 0.0;
        }
        sort(f, f+n, cmp);
        priority_queue<jobs, vector<jobs>, less<jobs> > que;
        double ans = 0.0, total = 0.0;
        for (int i = 0; i < n; i++) {
            total += f[i].b;
            que.push(f[i]);
            while ((total > f[i].d) && (!que.empty())) {
                jobs tmp = que.top();
                que.pop();
                double tmp2 = total - f[i].d;
                if (tmp2 <= (tmp.b - tmp.tx)) { 
                    total -= tmp2;
                    ans += tmp2 / tmp.a;
                    tmp.tx += tmp2;
                    que.push(tmp);
                    break;
                } else {
                    total -= (tmp.b - tmp.tx);
                    ans += (tmp.b - tmp.tx) / tmp.a;
                }
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
