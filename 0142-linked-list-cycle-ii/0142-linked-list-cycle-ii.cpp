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
    ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*>res;
        while(!res.count(head)&&head){
            res.insert(head);
            head=head->next;

        }
        return head;
    }
};