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
void reverse(ListNode* &curr,ListNode* prev,ListNode* &ans){
    if(!curr){
        ans=prev;
        return ;
    }
    reverse(curr->next,curr,ans);
    curr->next=prev;
}
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* ans=NULL;
        reverse(head,NULL,ans);
        return ans;
    }
};