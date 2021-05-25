/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head){
        vector<ListNode*> nodes;
        ListNode* node = head;
        while (node)
        {
            nodes.push_back(node);
            node = node->next;
        }

        if (nodes.size() > 2)
        {
            int left = 0;
            int right = nodes.size() - 1;
            while (right - left > 1)
            {
                nodes[left]->next = nodes[right];
                nodes[right]->next = nodes[left + 1];
                ++left;
                --right;
            }
            nodes[right]->next = nullptr;
        }
    }
};