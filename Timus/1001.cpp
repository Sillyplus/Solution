#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double a[1000101];

int main() {
    int i = 0, j;
    while (scanf("%lf", &a[i]) != EOF)
        ++i;
    for (int j = i-1; j >= 0; j--)
        printf("%.4lf\n", sqrt(a[j]));
    return 0;
}

//用G++4.7.2C++11的时候就WA，用G++4.7.2就AC了，这也是一个坑啊
