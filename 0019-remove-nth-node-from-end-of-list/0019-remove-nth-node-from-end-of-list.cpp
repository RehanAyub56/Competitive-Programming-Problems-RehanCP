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
        int cnt=0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }

        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int s=size(head);
        int i=s-n;
        if(i<0){
            i=0;
        }
        ListNode*temp=head;
        ListNode*List=new ListNode();
        ListNode*temp2=List;
        int index=0;
        while(temp!=NULL){
            if(i!=index){
                ListNode*newNode=new ListNode(temp->val);
                temp2->next=newNode;
                temp2=temp2->next;
            }

            index++;
            temp=temp->next;

        }



        return List->next;
        }

    };
