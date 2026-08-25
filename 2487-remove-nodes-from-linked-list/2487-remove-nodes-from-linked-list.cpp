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

    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode*temp=head;
        while(temp!=NULL){

            while(!st.empty() && temp->val>st.top()->val){
                st.top()->val=-1;
                st.pop();
            }

            st.push(temp);
            temp=temp->next;
        }


        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL && temp->next->val==-1){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }

        }
        if(head->val==-1){
            return head->next;
        }
        return head;
    }
};