#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MN = 10010;

struct ant{
    int id;
    int p;
    int d;
    bool operator < (const ant & a) const {
        return p < a.p;
    }
};

ant bg[MN], af[MN];
int order[MN];
char dir[][10] = {"L", "Turning", "R"};

int main() {
    int test, l, t, n;
    cin >> test;
    for (int cs = 1; cs <= test; cs++) {
        printf("Case #%d:\n", cs);
        scanf("%d%d%d", &l, &t, &n);
        for (int i = 0; i < n; i++) {
            int p, d;
            char c;
            scanf("%d %c", &p, &c);
            d = (c == 'L' ? -1 : 1);
            bg[i] = (ant) {i, p, d};
            af[i] = (ant) {0, p+t*d, d};
        }
        sort(bg, bg+n);
        for (int i = 0; i < n; i++)
            order[bg[i].id] = i;
        sort(af, af+n);
        for (int i = 0; i < n-1; i++)
            if (af[i].p == af[i+1].p)
                af[i].d = af[i+1].d = 0;
        for (int i = 0; i < n; i++) {
            int a = order[i];
            if (af[a].p < 0 || af[a].p > l)
                printf("Fell off\n");
            else
                printf("%d %s\n", af[a].p, dir[af[a].d+1]);
        }
        printf("\n");
    }
    return 0;
}
