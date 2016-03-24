/*******************************************************************************
	> File Name: 118.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Mar 24 18:15:14 2016
*******************************************************************************/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; ++i) {
            vector<int> tmp;
            if (i == 0) {
                tmp.push_back(1);
                
            } else {
                vector<int> pre = ret[i-1];
                tmp.push_back(1);
                for (int j = 1; j < pre.size(); ++j) {
                    tmp.push_back(pre[j] + pre[j-1]);
                }
                tmp.push_back(1);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
