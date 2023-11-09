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
           if (!head || !head->next) return head; // If no nodes or only one node, return as it is
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Keeping track of the start of even nodes
        
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next; // Connecting odd nodes
            odd = odd->next; // Move odd pointer
            
            even->next = odd->next; // Connecting even nodes
            even = even->next; // Move even pointer
        }
        
        odd->next = evenHead; // Connecting the last odd node with the start of even nodes
        
        return head;
    }
};