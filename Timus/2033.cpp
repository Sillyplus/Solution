/*******************************************************************************
	> File Name: 2033.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jan  7 21:37:49 2015
 ******************************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

map<string, int> device;
map<string, int> price;

int main() {
    string name, dev;
    int pri;
    for (int i = 0; i < 6; i++) {
        cin >> name >> dev >> pri;
        if (device.find(dev) == device.end()) {
            device[dev] = 1;
            price[dev] = pri;
        } else {
            device[dev]++;
            price[dev] = min(price[dev], pri);
        }
    }
    string ans;
    int tmp = 1e7, k = 0;
    map<string, int>::iterator itr;
    for (itr = device.begin(); itr != device.end(); itr++)
        if (itr->second > k || (itr->second == k && price[itr->first] < tmp)) {
            ans = itr->first;
            k = itr->second;
            tmp = price[itr->first];
        }
    cout << ans;
    return 0;
}
