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
    ListNode* insertionSortList(ListNode* head) {
         if (!head || !head->next) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* lastSorted = head;
        ListNode* curr = head->next;

        while (curr) {
            if (lastSorted->val <= curr->val) {
                // Already in correct position
                lastSorted = curr;
            } else {
                // Find correct position from start
                ListNode* prev = &dummy;
                while (prev->next->val < curr->val) {
                    prev = prev->next;
                }

                // Re-link nodes
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }

        return dummy.next;
    }
};