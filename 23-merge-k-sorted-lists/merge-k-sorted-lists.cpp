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
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val > l2->val){
           l2->next = mergeTwoSortedList(l1,l2->next);
           return l2;
        } 
        else{
            l1->next = mergeTwoSortedList(l1->next,l2);
            return l1;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0) return NULL;
        if(size == 1) return lists[0];

        queue<ListNode*> q;
        for(int i=0;i<size;i++){
            q.push(lists[i]);
        }

        while(q.size()!=1){
            ListNode* fir = q.front();
            q.pop();
            ListNode* sec = q.front();
            q.pop();
            ListNode* temp = mergeTwoSortedList(fir, sec);
            q.push(temp);
        }
        return q.front();
    }
};