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
    ListNode* doubleIt(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* curr=head;
        size_t a=0;
        while(curr!=NULL){
            a=a*10+curr->val;
            curr=curr->next;
        }
        a*=2;
        ListNode* head2=NULL;
        if(a==0){
            ListNode* newnode= new ListNode{0,head2};
            head2=newnode;
        }
        while(a!=0){
            int b=a%10;
            a/=10;
            ListNode* newnode= new ListNode{b,head2};
            head2=newnode;
        }
        return head2;
    }
};