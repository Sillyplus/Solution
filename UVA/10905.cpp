/*******************************************************************************
	> File Name: 10905.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Dec  5 09:30:33 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool cmp(const string & a, const string & b) {
    if ((a+b) == (b+a)) {
        return a.size() < b.size();
    } else {
        return (a+b) > (b+a);
    }
}

int main(int argc, char* argv[]) {
    int n;
    while (cin >> n && n != 0) {
        vector<string> v;
        string k;
        for (int i = 0; i < n; ++i) {
            cin >> k;
            v.push_back(k);
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); ++i)
            cout << v[i];
        cout << endl;
    }
    return 0;
}
