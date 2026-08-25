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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*temp=head;
        while(temp!=NULL){

                ListNode*curr=temp;
                temp=temp->next;
                int sum=0;
                while(temp!=NULL && temp->val!=0){
                    sum+=(temp->val);
                    temp=temp->next;
                }

                if(sum){
                ListNode*newNode=new ListNode();
                newNode->val=sum;
                newNode->next=temp;
                curr->next=newNode;
                }
                curr=NULL;
            
        }

        ListNode*List=NULL;
        temp=List;
        while(head!=NULL){
            if(head->val!=0){
                ListNode*newNode=new ListNode(head->val);
                if(temp!=NULL){
                    temp->next=newNode;
                    temp=temp->next;
                }
                else{
                    temp=newNode;
                    List=newNode;
                }
                cout<<newNode->val<<endl;

            }
            head=head->next;
        }


        return List;
    }
};