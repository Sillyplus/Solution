#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int MN = 110000;
const int INF = 100000000;

int n, m;
int heap[MN], id[MN], pos[MN];

void down(int k) {
    int x = heap[k], y = id[k];
    for (int i = k*2; i <= n; i *= 2) {
        i += i < n && heap[i] < heap[i+1];
        if (heap[i] > x) {
            heap[k] = heap[i];
            id[k] = id[i];
            pos[id[k]] = k;
            k = i;
        } else {
            break;
        }
    }
    heap[k] = x;
    id[k] = y;
    pos[y] = k;
}

void up(int k) {
    int x = heap[k], y = id[k];
    for (int i = k/2; i >= 1; i /= 2) {
        if (heap[i] < x) {
            heap[k] = heap[i];
            id[k] = id[i];
            pos[id[k]] = k;
            k = i;
        } else {
            break;
        }
    }
    heap[k] = x;
    id[k] = y;
    pos[y] = k;
}

void change(int k, int value) {
    heap[pos[k]] = value;
    down(pos[k]);
    up(pos[k]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        id[i] = pos[i] = i;
    char c[10];
    string s;
    int x, y;
    while (m--) {
        scanf("%s", c);
        s = string(c);
        if (s == "Yummy") {
            printf("%d\n", heap[1]);
        } else if (s == "Unlike") {
            scanf("%d", &x);
            change(x, -INF);
        } else if (s == "Like") {
            scanf("%d%d", &x, &y);
            change(x, y);
        }
    }
    return 0;
}
