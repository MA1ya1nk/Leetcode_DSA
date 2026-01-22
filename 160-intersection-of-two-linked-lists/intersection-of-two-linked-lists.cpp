/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0, len2=0;
        ListNode *first=headA, *second=headB;
        while(first){
            len1++;
            first=first->next;
        }
        while(second){
            len2++;
            second=second->next;
        }

        first=headA;
        second=headB;
        while(len1 > len2){
            first=first->next;
            len1--;
        }
        while(len2 > len1){
            second=second->next;
            len2--;
        }

        while(first && second && first!=second){
            first=first->next;
            second=second->next;
        }
        if(first==second) return first;
        return NULL;
    }
};