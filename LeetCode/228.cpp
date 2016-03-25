/*******************************************************************************
	> File Name: 228.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Mar 26 00:22:58 2016
*******************************************************************************/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        for (int i = 0; i < nums.size(); ) {
            int start = i;
            int end = i;
            while ((end+1) < nums.size()) {
                if (nums[end] == nums[end+1]-1) {
                    end++;
                    continue;
                } else {
                    break;
                }
            }
            if (start == end) {
                ret.push_back(toString(nums[start]));
            } else {
                ret.push_back(toString(nums[start]) + "->" + toString(nums[end]));
            }
            i = end + 1;
        }
        return ret;
    }
    
private:
    string toString(int xx) {
        long long x = xx;
        string ret = "";
        if (x == 0) {
            ret = "0";
        } else {
            bool flag = x < 0 ? true : false;
            if (x < 0) x *= -1;
            while (x) {
                ret = char('0' + (x % 10)) + ret;
                x /= 10;
            }
            if (flag) {
                ret = "-" + ret;
            }
        }
        return ret;
    }
};
