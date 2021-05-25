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
    ListNode* reverseNode(ListNode* n){
        ListNode *prev = NULL;
        ListNode *curr = n;
        ListNode *next = NULL;
        while(curr != NULL){
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp = new ListNode(0);
        ListNode* t1 = temp;
        
        ListNode* rev1 = reverseNode(l1);
        ListNode* rev2 = reverseNode(l2);
        
        while(rev1 || rev2){
            int x, y;
            x = rev1 != NULL ? rev1 -> val : 0;
            y = rev2 != NULL ? rev2 -> val : 0;
            
            int digit = carry + x + y;
            carry = digit /10;
            if(digit > 9)
                digit %=10;
            
            t1 -> next = new ListNode(digit);
            t1 = t1 -> next;
            
            if(rev1)
                rev1 = rev1 -> next;
            if(rev2)
                rev2 = rev2 -> next;
  
        }
        if(carry)
            t1 -> next = new ListNode(carry);
        
        
        ListNode* result = reverseNode(temp-> next);
        
        return result;
        
    }
};