#include <iostream>
#include <set>
#include <string>

using namespace std;

set<pair<string, string> > data;
set<string> user;
set<string> login;


int main() {
    int n;
    cin >> n;
    string order, name, passwd;
    for (int i = 0; i < n; i++) {
        cin >> order >> name;
        if (order == "register") {
            cin >> passwd;
            if (user.find(name) != user.end()) {
                cout << "fail: user already exists" << endl;
            } else {
                cout << "success: new user added" << endl;
                user.insert(name);
                data.insert(make_pair(name, passwd));
            }
        } else if (order == "login") {
            cin >> passwd;
            if (user.find(name) == user.end()) {
                cout << "fail: no such user" << endl;
            } else if (data.find(make_pair(name, passwd)) == data.end()) {
                cout << "fail: incorrect password" << endl;
            } else if (login.find(name) != login.end()) {
                cout << "fail: already logged in" << endl;
            } else {
                cout << "success: user logged in" << endl;
                login.insert(name);
            }
        } else {
            if (user.find(name) == user.end()) {
                cout << "fail: no such user" << endl;
            } else if (login.find(name) == login.end()) {
                cout << "fail: already logged out" << endl;
            } else {
                cout << "success: user logged out" << endl;
                login.erase(name);
            }
        }
    }
    return 0;
}
