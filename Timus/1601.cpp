/*******************************************************************************
	> File Name: 1601.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jan 12 22:17:51 2015
 ******************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    char c;
    bool flag = true;
    while (scanf("%c", &c) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            if (flag) {
                printf("%c", c);
                flag = false;
            } else {
                printf("%c", c + 32);
            }
        } else if (c == '.' || c == '!' || c == '?') {
            flag = true;
            printf("%c", c);
        } else {
            printf("%c", c);
        }
    }
    return 0;
}
