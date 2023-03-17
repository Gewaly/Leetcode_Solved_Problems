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
    ListNode* reverseList(ListNode* head) {
        ListNode* result=NULL;
        ListNode* nod=head;
        vector<int>arr;
        while(nod){
            arr.push_back(nod->val);
            nod=nod->next;
        }
        reverse(arr.begin(),arr.end());
        for(auto x: arr) cout<<x<<" ";
        nod=head;
        for(auto x: arr){
            nod->val=x;
            nod=nod->next;
        }
        
        return head;
        
    }
};