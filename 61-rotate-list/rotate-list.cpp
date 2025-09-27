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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        unordered_map<ListNode*,ListNode*> prev;
        ListNode* temp=head;
        int size=0;
        while(temp->next){
            prev[temp->next]=temp;
            size++;
            temp=temp->next;
        }
        size++;
        k=k%size;
        while(k--){
           prev[temp]->next=NULL;
           temp->next=head;
           head=temp;
           temp=prev[temp];
        }
        return head;
    }
};