#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char c[110];

int main() {
    int n;
    cin >> n;
    while (n--) {
        memset(c, 0, sizeof(c));
        scanf("%s", c);
        int k = 0;
        while (!(c[k] == '_' || c[k] == '\0')) k++;
        for (int i = k-1; i >= 0; i--)
            printf("%c", c[i]);
        if (c[k] == '_') {
            printf("_");
            int kk = k+1;
            while (c[kk] != '\0') kk++;
                for (int i = kk-1; i > k; i--)
            printf("%c", c[i]);
        }
        printf("\n");
    }
    return 0;
}
