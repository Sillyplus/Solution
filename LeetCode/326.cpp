/*******************************************************************************
	> File Name: 326.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Mar  7 10:04:06 2016
*******************************************************************************/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n > 0 && (1162261467) % n == 0) {
            return true;
        }
        return false;
    }
};
