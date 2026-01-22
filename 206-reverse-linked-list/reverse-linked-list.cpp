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
    ListNode* reverseList(ListNode* prev, ListNode* curr, ListNode* forw){
        if(!forw){
            curr->next=prev;
            return curr;
        }
        curr->next=prev;
        return reverseList(curr,forw,forw->next);
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr=head, *forw=head->next, *prev=NULL;
        return reverseList(prev,curr,forw);       
    }
};