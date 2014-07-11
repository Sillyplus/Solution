//
//  main.cpp
//  queue1
//
//  Created by Silly on 14-2-9.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[])
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.size() << endl;
    cout << q.empty() << endl;
    cout << q.front() << endl;
    cout << q.back() << endl;
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    cout << endl;
    return 0;
}

