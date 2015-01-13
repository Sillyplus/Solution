/*******************************************************************************
	> File Name: 1136.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jan 13 20:58:52 2015
 ******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 3010;

int inorder[MAXN], postorder[MAXN];

void sol(int n, int *postorder, int *inorder) {
    if (n <= 0)
        return;
    int p = find(inorder, inorder+n, postorder[n-1]) - inorder;
    sol(n-p-1, postorder+p, inorder+p+1);
    sol(p, postorder, inorder);
    cout << postorder[n-1] << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
        inorder[i] = postorder[i];
    }
    sort(inorder, inorder+n);
    sol(n, postorder, inorder);
    return 0;
}
