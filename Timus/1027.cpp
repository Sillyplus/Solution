/*******************************************************************************
	> File Name: 1027.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon May 11 15:25:26 2015
*******************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

string str, tmp;

int main() {

    while (getline(cin, tmp))
        str += tmp;
    
    bool flag = false, comm = false;

    int len = str.length(), le = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] != '*' && comm)
            continue;
        if (str[i] == '(') {
            if (i < len-1 && str[i+1] == '*')
                i++, comm = true;
            else 
                le++;
            continue;
        }
        if (str[i] == '*') {
            if (i < len-1 && str[i+1] == ')' && comm)
                i++, comm = false;
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '=')
            continue;
        if (str[i] == ')') {
            le--;
            if (le < 0) {
                flag = false;
                break;
            }
            continue;
        }
        if (le == 0)
            continue;
        flag = false;
        break;
    }
    if (comm || le != 0)
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;
    return 0;
}
