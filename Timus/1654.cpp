#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 200010;

char s[MAXN], sk[MAXN];

int main() {
    cin >> s;
    int top = 0;
    for (int i = 0; s[i]; i++) {
        if (top == 0 || s[i] != sk[top]) {
            sk[++top] = s[i];
        } else {
            if (s[i] == sk[top]) {
                top--;
            } else {
                sk[++top] = s[i];
            }
        }
    }
    for (int i = 1; i <= top; i++)
        printf("%c", sk[i]);
    cout << endl;
    return 0;
}
