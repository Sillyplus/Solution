/*******************************************************************************
	> File Name: 120.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Mar 24 18:44:15 2016
*******************************************************************************/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ret = 0;
        if (n == 0) {
            return ret;
        } else {
            ret = 2147483647;
        }
        vector<int> pre = triangle[0];
        for (int i = 1; i < n; ++i) {
            vector<int> tmp;
            vector<int> now = triangle[i];
            tmp.push_back(pre[0] + now[0]);
            for (int j = 1; j < pre.size(); ++j) {
                tmp.push_back(min(pre[j-1], pre[j]) + now[j]);
            }
            tmp.push_back(pre[pre.size()-1] + now[now.size()-1]);
            pre = tmp;
        }
        for (int i = 0; i < pre.size(); ++i) {
            ret = min(ret, pre[i]);
        }

        return ret;
    }
};
