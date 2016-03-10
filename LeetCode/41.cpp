/*******************************************************************************
	> File Name: 41.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Mar  9 10:53:55 2016
*******************************************************************************/

class Solution {
    public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) 
                swap(nums[i], nums[nums[i] - 1]);
        }

        int ret = 1;
        for (ret = 1; ret <= n; ++ret) 
            if (nums[ret-1] != ret)
                break;
        return ret;
    }
};
