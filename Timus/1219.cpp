#include <cstdio>

int main() {
    char a, b, c;
    for (int i = 0; i < 333333; i++) {
        a = char((i/676) % 26 + 'a');
        b = char((i/26) % 26 + 'a');
        c = char(i % 26 + 'a');
        printf("%c%c%c", a, b, c);
    }
    printf("a");
    return 0;
}
