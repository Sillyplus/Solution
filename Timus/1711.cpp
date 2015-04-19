/*******************************************************************************
	> File Name: 1711.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Apr 18 07:24:53 2015
*******************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct prob{
    int id;
    string st[3];
};

prob pb[22];
string ans[22];

bool comp(const prob &a, const prob &b) {
    return a.id < b.id;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> pb[i].st[j];
        }
        sort(pb[i].st, pb[i].st+3);
    }
    int k;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        pb[k-1].id = i;
    }
    
    sort(pb, pb+n, comp);
    
    // for (int i = 0; i < n; i++)
    //     cout << pb[i].id << " ";
    // cout << endl;

    bool flag = true;
    // for (int i = 0; i < n; i++) {
    //     cout << pb[i].id << " ";
    //     for (int j = 0; j < 3; j++) 
    //         cout << pb[i].st[j] << " ";
    //     cout << endl;
    // }

    ans[0] = pb[0].st[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) 
        if (pb[i].st[j] > ans[i-1]) {
            ans[i] = pb[i].st[j];
            break;
        }
        if (ans[i] == "") {
            flag = false;
            // cout << "Break with id: " << i << endl;
            // for (int j = 0; j < i; j++)
            //     cout << ans[j] << " ";
            // cout << endl;
            break;
        }
    }

    if (flag == false) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; i++)
            cout << ans[i] << endl;
    }

    return 0;
}
