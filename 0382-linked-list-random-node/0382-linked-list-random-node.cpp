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
      vector<int>arr;
    int n;
    Solution(ListNode* head) {
      
        ListNode* new_node=head;
        while(new_node){
             arr.push_back(new_node->val);
            new_node = new_node->next;
        }
            n = arr.size();
    }
    
    int getRandom() {
        static int i;
        if (i==0)
        {
            srand(time(NULL));
            i++;
        }
        return arr[rand() % n];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */