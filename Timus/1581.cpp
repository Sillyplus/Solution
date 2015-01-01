/*******************************************************************************
	> File Name: 1581.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Dec 29 07:53:37 2014
 ******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > v;

int main() {
    int n, count = 0, num = -1, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k == num) {
            count++;
        } else {
            v.push_back(make_pair(count, num));
            num = k;
            count = 1;
        }
    }
    v.push_back(make_pair(count, num));
    for (int i = 1; i < v.size(); i++)
        cout << v[i].first << " " << v[i].second << " ";
    cout << endl;
    return 0;
}
