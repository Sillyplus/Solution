/*******************************************************************************
	> File Name: 258.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Mar 23 09:14:35 2016
*******************************************************************************/

// https://en.wikipedia.org/wiki/Digital_root
//
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0)
            return 9;
        else 
            return num % 9;
    }
};
