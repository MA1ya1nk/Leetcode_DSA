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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode* first=new ListNode(-1), *second=new ListNode(-2);
        ListNode* temp=head, *firstHead=first, * secondHead=second;
        int len=0;
        while(temp){
            ListNode* forw=temp->next;
            if(len%2==0){
                first->next=temp;
                first=first->next;
            }
            else{
                second->next=temp;
                second=second->next;
            }
            len++;
            temp->next=NULL;
            temp=forw;
        }
        first->next=secondHead->next;
        return firstHead->next;
    }
};