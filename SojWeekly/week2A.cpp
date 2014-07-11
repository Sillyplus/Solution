//
//  main.cpp
//  week2A
//
//  Created by Silly on 14-3-8.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>

const int MN = 50010;

using namespace std;

int b[MN] = {0}, e[MN] = {0};
char fb[MN], fe[MN];

int main(int argc, const char * argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &b[i], &fb[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %c", &e[i], &fe[i]);
    }
    
    long long eb = 0, ee = 0;
    int ans = 0;
    int nb = 0, ne = 0;
    bool flag = false;
    while (b[n-1] || e[m-1]) {
        if (eb == ee) {
            flag = true;
        } else flag = false;
        if (!b[nb] && b[n-1]) nb++;
        if (!e[ne] && e[m-1]) ne++;
        if ((fb[nb] == 'L') && b[nb]) {
            eb--;
            b[nb]--;
        }
        if ((fb[nb] == 'R') && b[nb]) {
            eb++;
            b[nb]--;
        }
        if ((fe[ne] == 'L') && e[ne]) {
            ee--;
            e[ne]--;
        }
        if ((fe[ne] == 'R') && e[ne]){
            ee++;
            e[ne]--;
        }
        //cout << eb << ' ' << ee << endl;
        if ((eb == ee) && !flag) {
            ans++;
            //cout << eb << ' ' << ee << endl;
        }
    }
    cout << ans << endl;
    return 0;
}

