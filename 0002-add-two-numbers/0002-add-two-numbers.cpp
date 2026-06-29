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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1=new ListNode();
         ListNode *temp2=new ListNode();
        temp1=l1;
        temp2=l2;
        int rem=0;
        ListNode *head=new ListNode();
        ListNode* tail = head;
       while(temp1!=NULL && temp2!=NULL){
     ListNode *newNode = new ListNode();
    int curr = temp1->val + rem +temp2->val;   
    newNode->val = curr % 10;      
    rem = curr / 10;              
    tail->next = newNode;
    tail = newNode;                
    temp1 = temp1->next;
    temp2=temp2->next;
       }

      while(temp1 != NULL){
    ListNode *newNode = new ListNode();
    int curr = temp1->val + rem;   
    newNode->val = curr % 10;      
    rem = curr / 10;              
    tail->next = newNode;
    tail = newNode;                
    temp1 = temp1->next;
}

       while(temp2!=NULL){
 ListNode *newNode = new ListNode();
    int curr = temp2->val + rem;   
    newNode->val = curr % 10;      
    rem = curr / 10;              
    tail->next = newNode;
    tail = newNode;                
    temp2 = temp2->next;
       }

       if(rem){
        ListNode *newNode = new ListNode();
  
    newNode->val = rem;                   
    tail->next = newNode;
    tail = newNode;                
 
       }


        return head->next;
        
    }
};