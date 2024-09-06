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
    ListNode* createLinkedList(const vector<int>& vec) {
    if (vec.empty())return nullptr;
    ListNode* head=new ListNode(vec[0]);
    ListNode* current=head;
    for (int i=1;i<vec.size();i++) {
        current->next=new ListNode(vec[i]);
        current=current->next;
    }
    return head;
}
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* cur=head;
        vector<int>res;
        while(cur!=NULL){
            res.push_back(cur->val);
                cur=cur->next;

        }
            unordered_set<int> setNums(nums.begin(), nums.end());
        res.erase(remove_if(res.begin(), res.end(), 
                         [&setNums](int x) {
                             return setNums.count(x) > 0;
                         }), 
               res.end());
            ListNode* gogo = createLinkedList(res);
        return gogo;

        
       
        
    }
};