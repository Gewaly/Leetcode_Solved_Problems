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
    int x = 0;
    ListNode* q;
    void solve(ListNode* p, int &k){
        if(p==NULL){
            x = -1;
            return;
        }
        solve(p->next,k);
        k--;
        if(k==0){
            swap(p->val,q->val);
            return;
        }
        q = q->next;

    }
    ListNode* swapNodes(ListNode* head, int k) {
        q = head;
        solve(head,k);
        return head;
    }
};