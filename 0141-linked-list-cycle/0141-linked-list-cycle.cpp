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
    bool hasCycle(ListNode *head) {
        ListNode*fast=head;
        ListNode*slow=head;
        

        while(fast!=NULL && slow!=NULL && fast->next!=NULL && slow->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==NULL || fast==NULL || slow->next==NULL || fast->next==NULL){
                return false;
            }

            if(slow==fast){
                return true;
 
            }

        }

        return false;

    }
};