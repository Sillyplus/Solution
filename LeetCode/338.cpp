/*******************************************************************************
	> File Name: 338.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Mar 19 01:41:41 2016
*******************************************************************************/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        ret.push_back(0);
        int k = 0;
        for (int i = 1; ; ++i) {
            int base = 1 << i-1;
            for (int j = base; j < (1 << i); ++j) {
                if (j > num) return ret;
                ret.push_back(ret[j - base] + 1);
            }
        }
        return ret;
    }
};
