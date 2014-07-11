#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 103;

typedef struct {
    int lc,rc;
    int val;
}Node;

Node tree[MAXN];
int m,n;
int arr[MAXN][MAXN];
int f[MAXN][MAXN];
int vis[MAXN];

void Create(int root) {
    vis[root] = 1;
    for(int i = 1; i <= m; i++) {
        if(!vis[i] && arr[root][i]) {
            if(!tree[root].lc)
                tree[root].lc = i;
            else 
                tree[root].rc = i;
            tree[i].val = arr[root][i];
            Create(i);
        }
    }
}

int TreeDP(int root, int e) {
    if(!root || !e) return 0;
    if(f[root][e]) return f[root][e];
    int maxx = 0;
    int l,r;
    for(int i = 0; i < e; i++) {
        l = TreeDP(tree[root].lc, i);
        r = TreeDP(tree[root].rc, e-i-1);
        maxx = max(l+r, maxx);
    }
    f[root][e] = maxx + tree[root].val;
    return f[root][e];
}

int main() {
    scanf("%d %d", &m, &n);
    int l,f,v;
    for(int i = 1; i < m; i++) {
        scanf("%d %d %d", &l, &f, &v);
        arr[l][f] = arr[f][l] = v;
    }
    Create(1);
    printf("%d\n", TreeDP( 1, ++n));
    return 0;
}
