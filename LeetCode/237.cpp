/*******************************************************************************
	> File Name: 237.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Mar 25 02:30:56 2016
*******************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node != NULL) {
            ListNode* tmp = node->next;
            node->val = tmp->val;
            node->next = tmp->next;
            delete tmp;
        }
    }
};
