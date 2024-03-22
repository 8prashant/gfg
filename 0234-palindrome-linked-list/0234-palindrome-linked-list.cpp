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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        stack<int> s;
        while(fast!=NULL && fast->next!=NULL){
            s.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL && fast->next==NULL){
            slow=slow->next;
        }
        while(slow!=NULL){
            // cout<<curr->val<<" "<<slow->val<<endl;
            if(s.top()!=slow->val){
                return false;
            }
            slow=slow->next;
            s.pop();
        }
        return true;
    }
};