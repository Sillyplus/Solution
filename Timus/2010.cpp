/*******************************************************************************
	> File Name: 2010.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jan 12 23:32:58 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

int n;
int dx1[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy1[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx2[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy2[] = {-2, -1, 1, 2, -2, -1, 1, 2};

bool check(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n)
        return false;
    return true;
}

int main() {
    int x, y;
    cin >> n;
    cin >> x >> y;
    int king, knight, bishop, rook, queen;
    king = knight = bishop = rook = queen = 0;
    for (int i = 0; i < 8; i++) {
        if (check(x+dx1[i], y+dy1[i])) king++;
        if (check(x+dx2[i], y+dy2[i])) knight++;
    }
    if (x+y-1 > n) 
        bishop += (2*n - (x+y-1));
    else 
        bishop += (x+y-1);
    if (n-x+y > n)
        bishop += (2*n - (n-x+y));
    else 
        bishop += (n-x+y);
    bishop -= 2;
    rook = 2 * n - 2;
    queen = bishop + rook;
    cout << "King: " << king << endl;
    cout << "Knight: " << knight << endl;
    cout << "Bishop: " << bishop << endl;
    cout << "Rook: " << rook << endl;
    cout << "Queen: " << queen << endl;
    return 0;
}
