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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        unordered_map<ListNode*,ListNode*> prev;
        while(temp->next){
            prev[temp->next]=temp;
            temp=temp->next;
        }
        while(head!=temp){
            if(head->val != temp->val) return false;
            head=head->next;
            temp=prev[temp];
        }
        return true;
    }
};