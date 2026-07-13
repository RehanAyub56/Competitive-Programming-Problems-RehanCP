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

    int size(ListNode*head){
        ListNode*temp=new ListNode();
        temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }

        return cnt;
    }
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        int s=size(head);
        int i=0;
        if(s==1){
            return;
        }
        ListNode*temp=head;
        while(i<(s+1)/2 && temp!=NULL){
            temp=temp->next;
            i++;
        }
        ListNode*temp2=new ListNode();
        temp2=temp;
        while(temp2!=NULL){
            ListNode*newNode=new ListNode();
            newNode->val=temp2->val;
            newNode->next=NULL;
            st.push(newNode);
            temp2=temp2->next;
        }

        temp->next=NULL;
        temp=head;

        while(!st.empty()){
            cout<<st.top()->val<<" ";
            st.top()->next=temp->next;
            temp->next=st.top();
            st.pop();
            temp=temp->next->next;
        }
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;

    }
};