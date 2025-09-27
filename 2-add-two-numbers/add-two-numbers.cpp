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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rem=0;
        ListNode* temp=new ListNode(0);
        ListNode* ans=temp;
        while(l1 && l2){
            int sum=rem+l1->val + l2->val;
            l1=l1->next;
            l2=l2->next;
            rem=sum/10;
            sum%=10;
            temp->next=new ListNode(sum);
            temp=temp->next;
        }
        ListNode* tem=(l1)?l1:l2;
        while(tem){
            int sum=rem+tem->val;
            tem=tem->next;
            rem=sum/10;
            sum%=10;
            temp->next=new ListNode(sum);
            temp=temp->next;
        }
        if(rem) temp->next=new ListNode(rem);
        return ans->next;
    }
};