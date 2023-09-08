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
    ListNode* solve(ListNode* head, int right){
        ListNode* store = head;
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* forward;
        
        for(int i=0; i<right; i++){
            forward = temp->next;
            temp -> next = prev;
            
            prev = temp;
            temp = forward;
        }
        
        store -> next = temp;
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        if(left == 1) return solve(head, right);
        
        int i = 2;
        int len = right-left+1;
        ListNode* temp = head;
        
        while(i<left){
            temp = temp -> next;
            i++;
        }
        
        ListNode* store1 = temp;
        ListNode* store2 = temp -> next;

        temp = temp -> next;        
        ListNode* prev = NULL;
        ListNode* forward;
        
        for(int i=0; i<len; i++){
            forward = temp->next;
            temp -> next = prev;
            
            prev = temp;
            temp = forward;
        }
        
        store1 -> next = prev;
        store2 -> next = temp;
        
        return head;
    }
};