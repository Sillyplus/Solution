/*******************************************************************************
	> File Name: 191.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Mar  7 10:25:08 2016
*******************************************************************************/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = n;
        ret = (ret & 0x55555555) + ((ret >> 1) & 0x55555555);
        ret = (ret & 0x33333333) + ((ret >> 2) & 0x33333333);
        ret = (ret & 0x0F0F0F0F) + ((ret >> 4) & 0x0F0F0F0F);
        ret = (ret & 0x00FF00FF) + ((ret >> 8) & 0x00FF00FF);
        ret = (ret & 0x0000FFFF) + ((ret >> 16) & 0x0000FFFF);
        return ret;
    }
};
