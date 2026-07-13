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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*temp1=list1;
        ListNode*temp2=list2;
        ListNode*Link=new ListNode();
        ListNode*temp3=Link;
        while(temp1!=NULL && temp2!=NULL){
            ListNode*newNode=new ListNode();
            if(temp1->val<=temp2->val){
                newNode->val=temp1->val;
                if(temp3==NULL){
                    temp3=newNode;
                }
                else{
                    temp3->next=newNode;
                    temp3=temp3->next;
                }
                temp1=temp1->next;
            }
            else{
                newNode->val=temp2->val;
                if(temp3==NULL){
                    temp3=newNode;
                }
                else{
                    temp3->next=newNode;
                    temp3=temp3->next;
                }
                temp2=temp2->next;
            }

        }

        while(temp1!=NULL){
        ListNode*newNode=new ListNode();
        newNode->val=temp1->val;
        temp3->next=newNode;
        temp1=temp1->next;
        temp3=temp3->next;
           
        }

        while(temp2!=NULL){
        ListNode*newNode=new ListNode();
        newNode->val=temp2->val;
        temp3->next=newNode;
        temp2=temp2->next;
        temp3=temp3->next;
           
        }
       


        return Link->next;

    }
};