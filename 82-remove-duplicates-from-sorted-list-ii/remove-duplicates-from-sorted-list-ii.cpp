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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> freq;
        ListNode* temp = head;
        while(temp){
            freq[temp->val]++;
            temp = temp->next;
        }

        ListNode* tem = new ListNode(-1);
        ListNode* ans = tem;
        temp = head;
        while(temp){
            if(freq[temp->val]==1){
                tem->next = new ListNode(temp->val);
                tem = tem->next;
            }
            temp=temp->next;
        }

        return ans->next;
    }
};