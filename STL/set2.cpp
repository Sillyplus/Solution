//
//  main.cpp
//  set2
//
//  Created by Silly on 14-3-2.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

struct myComp{
    bool operator() (const int &a, const int &b){
        if (a != b)
            return a > b;
        else
            return a > b;
    }
};

struct Info{
    string name;
    float score;
    bool operator< (const Info &a) const{
        return a.score < score;
    }
};

int main(int argc, const char * argv[])
{
    /*
    set<int, myComp> s;
    s.insert(8);
    s.insert(1);
    s.insert(12);
    s.insert(6);
    s.insert(8);
    set<int, myComp>::iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    
    */
    set<Info> s;
    Info info;
    info.name = "Jack";
    info.score = 80.5;
    s.insert(info);
    info.name = "Tomi";
    info.score = 20.5;
    s.insert(info);
    info.name = "Nacy";
    info.score = 60.5;
    s.insert(info);
    set<Info>::iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        cout << (*it).name << " " << (*it).score << endl;
    }
    return 0;
}

