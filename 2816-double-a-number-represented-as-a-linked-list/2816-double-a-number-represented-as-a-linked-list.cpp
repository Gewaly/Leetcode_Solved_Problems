class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* list=head;
        stack<int> s,a;
        while(list)
        {
            s.push(list->val);
            list=list->next;
        }
        int c=0;
        while(s.size()!=0)
        {
            int num=s.top();
            s.pop();
            num=num*2+c;
            a.push(num%10);
            c=num/10;
        }
        if(c)
        {
            a.push(c);
        }
        ListNode* result = nullptr;
        ListNode* tail = nullptr;
        while (!a.empty()) {
            ListNode* newNode = new ListNode(a.top());
            a.pop();
            if (!result) {
                result = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        
        return result;
    }
};