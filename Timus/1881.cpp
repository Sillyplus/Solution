/*******************************************************************************
	> File Name: 1881.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Dec 29 08:09:34 2014
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int now = 0, count = 1;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (now == 0) {
            now = s.size();
        } else {
            if (now + 1 + s.size() > w) {
                now = s.size();
                count++;
            } else {
                now += (1 + s.size());
            }
        }
    }
    cout << (count % h == 0 ? count / h : count / h + 1) << endl;
    return 0;
}
