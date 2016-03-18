/*******************************************************************************
	> File Name: 337.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Mar 19 02:00:00 2016
*******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> ret = value(root);
        return max(ret[0], ret[1]);
    }
    
    vector<int> value(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) {
            ret.push_back(0);
            ret.push_back(0);
            return ret;
        }
        if (root->left == NULL && root->right == NULL) {
            ret.push_back(0);
            ret.push_back(root->val);
            return ret;
        }
        vector<int> leftRet = value(root->left);
        vector<int> rightRet = value(root->right);
        ret.push_back(max(leftRet[0], leftRet[1]) + max(rightRet[0], rightRet[1]));
        ret.push_back(leftRet[0] + rightRet[0] + root->val);
        return ret;
    }
};
