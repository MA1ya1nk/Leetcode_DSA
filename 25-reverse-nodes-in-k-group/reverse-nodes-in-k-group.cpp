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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* temp = head;
        while(cnt<k){
            cnt++;
            if(!temp) return head;
            temp=temp->next;
        }
        cnt = 0;
        temp = head;
        ListNode* prev = NULL, *curr = head;
        while(cnt<k){
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
            cnt++;
        }
        temp->next = reverseKGroup(curr,k);
        return prev;
    }
};