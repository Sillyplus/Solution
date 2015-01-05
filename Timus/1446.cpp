/*******************************************************************************
	> File Name: 1446.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jan  5 15:33:26 2015
 ******************************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, vector<string> > mp;
string v[4] = {"Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw"};
int main() {
    int n;
    string house, name;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, name);
        getline(cin, house);
        mp[house].push_back(name);
    }
    for (int i = 0; i < 4; i++) {
        cout << v[i] << ":" << endl;
        for (int j = 0; j < mp[v[i]].size(); j++)
            cout << mp[v[i]][j] << endl;
        cout << endl;
    }
    return 0;
}
