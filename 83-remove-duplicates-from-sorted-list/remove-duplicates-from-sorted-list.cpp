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
        set<int> s;
        ListNode* temp = head;
        while(temp){
            s.insert(temp->val);
            temp = temp->next;
        }
         ListNode* tem = new ListNode(1);
         temp=tem;
        while(!s.empty()){
            int top = *(s.begin());
             s.erase(s.begin());
            tem->next = new ListNode(top);
            tem = tem->next;
        }

        return temp->next;
    }
};