/*******************************************************************************
	> File Name: 1496.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun Jan  4 07:26:48 2015
 ******************************************************************************/

#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> s1, s2;

int main() {
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s1.find(s) != s1.end())
            s2.insert(s);
        else 
            s1.insert(s);
    }
    set<string>::iterator its;
    for (its = s2.begin(); its != s2.end(); its++) 
        cout << *its << endl;
    return 0;
}
