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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* oddHead = odd;
        ListNode* evenHead = even;
        ListNode* curr = head;
        bool flag = false;
        while(curr != NULL){
            if(flag == false){
                odd -> next = new ListNode(curr -> val); 
                odd = odd -> next;
                
            }else{
                even -> next = new ListNode(curr -> val);
                even = even -> next;
            }
            curr = curr -> next;
            flag = !flag;
        }
        odd -> next = evenHead -> next;
    return oddHead -> next;
    }
};