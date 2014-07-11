//
//  main.cpp
//  string1
//
//  Created by Silly on 14-1-25.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

string converToString(double x){
    ostringstream o;
    if (o << x) {
        return o.str();
    }
    return "conversion error";
}

double converFromString(const string &s){
    istringstream i(s);
    double x;
    if (i >> x) {
        return x;
    }
    return 0.0;
}

int main(int argc, const char * argv[])
{
    char b[10];
    string a;
    sprintf(b, "%d", 1975);
    a = b;
    cout << a << endl;
    int x = 1976;
    ostringstream o;
    o << x;
    a = o.str();
    cout << a << endl;
    istringstream i("2014");
    i >> x;
    cout << x << endl;
    //string cc = converToString(1976);
    //cout << cc << endl;
    //string dd = "2013";
    //int p = converFromString(dd) + 1;
    //cout << p << endl;
    
    
    
    /*
    string  s1, s2, s3;
    char sa[100], sb[100], sc[100];
    sscanf("abc 123 pc", "%s %s %s", sa, sb, sc);
    s1 = sa;
    s2 = sb;
    s3 = sc;
    cout << s1 << " " << s2 << " " << s3 << endl;
    int a, b, c;
    sscanf("1 2 3", "%d %d %d", &a, & b, &c);
    cout << a << " " << b << " " << c << endl;
    int x, y, z;
    sscanf("4,5$6", "%d,%d$%d", &x, &y, &z);
    cout << x << " " << y << " " << z << endl;
    */
    
    /*
    string s;
    char ss[100];
    scanf("%s", &ss);
    s = ss;
    printf(s.c_str());
    cout << endl;
    printf("%s", ss);
    cout << endl;
    cout << s << endl;
    cout << ss << endl;
    */
    
    
    /*
    string s;
    
    s = s + 'a';
    s += 'b';
    s = s + 'c';
    cout << s << endl;
    s += "123xcv";
    cout << s << endl;
    
    
    
    s = "";
    s.append("abc");
    s.append("Hello");
    cout << s << endl;
    
    
    s = "123456";
    cout << endl;
    string::iterator it;
    it = s.begin();
    s.insert(it + 1, 'x');
    cout << s << endl;
    
    
    cout << s[1] << endl;
    cout << s[1] - 'a' << endl;
    
    
    s.erase(it);
    cout << s << endl;
    s.erase(it, it + 3);
    cout << s << endl;
    
    cout << s.length() << endl;
    cout << s.empty() << endl;
    s = "";
    cout << s.empty() << endl;
    
    
    s = "abcde World!";
    cout << s << endl;
    s.replace(it, it + 5, "Hello");
    cout << s << endl;
    
    
    s = "cat dog cat";
    cout << s.find('c') << endl;
    cout << s.find("c") << endl;
    cout << s.find("cat") << endl;
    cout << s.find("dog") << endl;
    cout << s.find("dogc") << endl;
    
    cout << s.compare("cat") << endl;
    cout << s.compare("cat dog cat") << endl;
    cout << s.compare("dog") << endl;
    
    if (s < "dog") {
        cout << "Ni Hao" << endl;
    } else {cout << "Bu Hao" << endl;
    }
    
    s = "1234567890";
    cout << s << endl;
    reverse(s.begin(), s.end());
    cout << s << endl;
    
    vector<string> v;
    v.push_back("Jack");
    v.push_back("Mike");
    v.push_back("Tom");
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[0][0] << endl;
    cout << v[2][2] << endl;
    cout << v[1].length() << endl;
    
    */
    
    /*
    char ss[100];
    scanf("%s", &ss);
    s = ss;
    //s = "Hello, C++ STL.";
    cout << s.length() << endl;
    cout << s << endl;
    */
    
    
    return 0;
}

