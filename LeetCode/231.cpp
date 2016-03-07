/*******************************************************************************
	> File Name: 231.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Mar  7 10:09:01 2016
*******************************************************************************/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n > 0 && (1073741824 % n == 0)) {
            return true;
        }
        return false;
    }
};
