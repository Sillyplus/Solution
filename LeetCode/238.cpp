/*******************************************************************************
	> File Name: 238.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Mar 15 00:35:03 2016
*******************************************************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        vector<int> ret;
        long long pd = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                pd *= nums[i];
            } else {
                zeroCount++;
            }
        }
        if (zeroCount >= 2) {
            for (int i = 0; i < nums.size(); ++i) {
                ret.push_back(0);
            }
        } else if (zeroCount == 1) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i]) {
                    ret.push_back(0);
                } else {
                    ret.push_back(pd);
                }
            }
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                ret.push_back(pd / nums[i]);
            }
        }
        return ret;
    }
};
