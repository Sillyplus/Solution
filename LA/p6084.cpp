#include <iostream>
#include <cstdio>

using namespace std;

int main (int argc, char const *argv[]){
    int l, v, p;
    int t = 1;
    scanf("%d%d%d", &l, &v, &p);
    while (!(l == 0 && v == 0 && p == 0)) {
        int m = p % v;
        if(l < m){
            m = l;
        }
        printf("Case %d: %d\n", t++, p/v*l + m);
        scanf("%d%d%d", &l, &v, &p);
    }
    return 0;
}
