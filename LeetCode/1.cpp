/*******************************************************************************
	> File Name: 1.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Mar 15 01:14:59 2016
*******************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(target - nums[i]) != mp.end()) {
                if (mp[target - nums[i]] != i) {
                    ret.push_back(i);
                    ret.push_back(mp[target - nums[i]]);
                  return ret;
                }
            }
        }
        return ret;
    }
};
