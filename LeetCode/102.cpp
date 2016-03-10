/*******************************************************************************
	> File Name: 102.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Mar  8 23:14:50 2016
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        
        if (root == NULL)
            return ret;
            
        q.push(root);
        q.push(NULL);
        
        while (!q.empty()) {
            vector<int> tmp;
            while (!q.empty()) {
                if (q.front() != NULL) {
                    TreeNode* tn = q.front();
                    tmp.push_back(tn->val);
                    if (tn->left != NULL) 
                        q.push(tn->left);
                    if (tn->right != NULL) 
                        q.push(tn->right);
                    q.pop();
                } else {
                    q.pop();
                    if (!q.empty()) 
                        q.push(NULL);
                    ret.push_back(tmp);
                    break;
                }
            }
        }
        
        return ret;
    }
};
