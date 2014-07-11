#include <iostream>
#include <cstdio>

using namespace std;

char a[300];

int main() {
    char c;
    int t = -1;
    while (1) {
        c = getchar();
        if (c == EOF) break;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            a[++t] = c;
        } else {
            for (int i = t; i >= 0; i--)
                printf("%c", a[i]);
            printf("%c", c);
            t = -1;
        }
    }
    for (int i = t; i >= 0; i--)
        printf("%c", a[i]);
    return 0;
}
