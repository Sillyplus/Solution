//
//  main.cpp
//  vector1
//
//  Created by Silly on 14-1-23.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool comp(const int &a,const int &b){
    if (a != b) {
        return a > b;
    } else return a > b;
}

int main(int argc, const char * argv[])
{
    
    vector<int> v(10);
    for (int i = 0; i < 10; i++) {
        v[i] = i;
    }
    reverse(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), comp);
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    cout << v.size() << endl;
    cout << v.empty() << endl;
    v.clear();
    cout << v.size() << endl;
    cout << v.empty() << endl;
    return 0;
    
    
    
    /*
    v.push_back(2);
    v.push_back(7);
    v.push_back(9);
    cout << v[0] << v[1] << v[2] << endl;
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << endl;
    }
    
    cout << endl;
    
    v.insert(v.begin(), 8);
    v.insert(v.begin() + 2, 1);
    v.insert(v.end(), 3);
    vector<int>::iterator it;
    for (it = v.begin(); it < v.end(); it++) {
        cout << *it << endl;
    }
    */
    
    
    /*
    vector<int>::iterator it;
    cout << endl;
    for (int i = 0; i < 10; i++) {
        v[i] = i;
    }
    for (it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    v.erase(v.begin() + 2);
    for (it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    v.erase(v.begin() + 1, v.begin() + 5);
    for (it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    v.clear();
    cout << v.size() << endl;
    return 0;
    */
    
    /*
    
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    cout << accumulate(v.begin(), v.end(), 0) << endl;
    return 0;
     
    */
    
}

