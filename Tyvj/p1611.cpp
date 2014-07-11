#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MN = 15;

string c[MN+5];
int n;

bool ck(int x, int y) {
    if (x >= 0 && x < MN && y >= 0 && y < MN) return true;
    return false;
}

bool row(char x) {
	for (int i = 0; i < MN; i++) {
		for (int j = 0; j < MN; j++) {
			if (c[i][j] == x) {
                int k = 1;
                while (c[i][j+k] == x && (j+k) < MN) k++;
                if (k >= 5) return true;
            }
		}
	}
    return false;
}

bool cul(char x) {
    for (int i = 0; i < MN; i++) {
        for (int j = 0; j < MN; j++) {
            if (c[j][i] == x) {
                int k = 1;
                while (c[j+k][i] == x && (j+k) < MN) k++;
                if (k >= 5) return true;
            }
        }
    }
    return false;
}

bool da(char x) {
    for (int i = 4; i < MN; i++) {
        for (int j = 0; j < MN; j++) {
            if (c[i][j] == x) {
                int k = 1;
                while (ck(i-k, j+k) && c[i-k][j+k] == x) k++;
                if (k >= 5) return true;
            }
        }
    }
    return false;
}

bool db(char x) {
    for (int i = 4; i < MN; i++) {
        for (int j = 0; j < MN; j++) {
            if (c[i][j] == x) {
                int k = 1;
                while (ck(i-k, j-k) && c[i-k][j-k] == x) k++;
                if (k >= 5) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n;
    while (n--) {
        for (int i = 0; i < MN; i++) {
            cin >> c[i];
        }
        bool bw, ww;
        bw = row('X') || cul('X') || da('X') || db('X');
        ww = row('O') || cul('O') || da('O') || db('O');
        if (bw == ww) {
            cout << "I don't know.\n";
        } else if (bw) {
            cout << "X win.\n";
        } else {
            cout << "O win.\n";
        }
    }
    return 0;
}
