#include <iostream>

using namespace std;

struct aa{
    int r, g, b;
    int x1, x2, y1, y2;
};

aa f[1010];

int main() {
    int n, m;
    cin >> n >> m;
    while ((n != 0) && (m != 0)) {
        aa k;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d%d%d%d%d", &f[i].x1, &f[i].y1, &f[i].x2, &f[i].y2, &f[i].r, &f[i].g, &f[i].b);
        }

        for (int i = 0; i < m; i++) {
            int j, x, y;
            scanf("%d%d", &x, &y);
            for (j = n; j > 0; j--) {
                if (x >= f[j].x1 && x <= f[j].x2 && y >= f[j].y1 && y <= f[j].y2) break;
            }
//            cout << j << endl;
            if (j) {
                printf("%d %d %d\n", f[j].r, f[j].g, f[j].b);
            } else {
                printf("255 255 255\n");
            }
        }
        cin >> n >> m;
    }
    return 0;
}
