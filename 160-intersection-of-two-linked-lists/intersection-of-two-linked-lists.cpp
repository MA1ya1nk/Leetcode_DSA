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
        unordered_map<ListNode*, bool> vis;
        ListNode* first=headA, *second=headB;
        while(first){
            vis[first] = true;
            first=first->next;
        }
        while(second){
            if(vis[second]) return second;
            second=second->next;
        }

        return NULL;
    }
};