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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        int len = size(head); 
        int index = len - n; 
        
        ListNode* iter = head;
        ListNode* trail = nullptr;
        
        for(int i=0; i<index; i++){
            trail = iter;
            iter = iter->next;
        }
        if(iter == head and len == 1){ 
            head = nullptr;
        }
        else if(iter == head){ 
            head = head->next;
        }
        else{ 
            trail->next = iter->next;
        }
        delete iter;
        
        return head;
    }
    
    int size(ListNode* head){
        if(!head) return 0;
        int size = {0};
        ListNode* curr = head;
        while(curr){
            size++;
            curr = curr->next;
        }
        return size;
    }
    
};
    
    
    
        